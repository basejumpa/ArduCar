
ifeq ($(filter $(MAKECMDGOALS),download daq elf unittest),)
ifndef UNITS
$(error fatal error: $(lastword $(MAKEFILE_LIST)) needs $$(UNITS))
endif

ifndef FLAVOR
$(error fatal error: $(lastword $(MAKEFILE_LIST)) needs $$(FLAVOR))
endif
endif

ifeq ($(filter $(MAKECMDGOALS),download daq),)
ifndef DEVICE
$(error fatal error: $(lastword $(MAKEFILE_LIST)) needs $$(DEVICE))
endif
endif

# = WORKFLOW
# |--------------------------- elf-| => |-------------------- daq-|
# |preproc+compile => link+relocate| => |download+run+daq|
#

FLAVORDIR=$(subst _,/,$(FLAVOR))
OUTDIR=out/$(FLAVORDIR)
BUILDLOG=$(OUTDIR)/build.log

INSTALL_PATH_ARDUINO=/usr/local/Arduino/

SOURCES := $(shell find src/ -type f -name '*.cpp' ! -name '*_test.cpp' | grep -E "$(UNITS)")
OBJECTS := $(addprefix $(OUTDIR)/,$(patsubst %,%.o,$(SOURCES)))
DEPS    := $(addprefix $(OUTDIR)/,$(patsubst %,%.d,$(SOURCES)))

TEST_SOURCES  := $(shell find src/ -type f -name '*_test.cpp' -not -path 'src/test/*' | grep -E ".*/.*/.*$(UNITS)")
TEST_OBJECTS  := $(addprefix $(OUTDIR)/,$(patsubst %,%.o,$(TEST_SOURCES)))
TEST_DEPS     := $(addprefix $(OUTDIR)/,$(patsubst %,%.d,$(TEST_SOURCES)))
TEST_OBJ_IUT  := $(addprefix $(OUTDIR)/,$(patsubst %,%.test.o,$(SOURCES)))
TEST_DEPS_IUT := $(addprefix $(OUTDIR)/,$(patsubst %,%.test.d,$(SOURCES)))
TEST_EXECS    := $(addprefix $(OUTDIR)/,$(patsubst %,%.exe,$(TEST_SOURCES)))

TEST_LOGS     := $(patsubst %,%.log,$(TEST_EXECS))

#.FORCE:
#$(TEST_LOGS): .FORCE


#$(info SOURCES      = $(SOURCES))
#$(info OBJECTS      = $(OBJECTS))
#$(info DEPS         = $(DEPS))

#$(info TEST_SOURCES = $(TEST_SOURCES))
#$(info TEST_OBJECTS = $(TEST_OBJECTS))

#$(info TEST_DEPS    = $(TEST_DEPS))
#$(info TEST_OBJ_IUT = $(TEST_OBJ_IUT))
#$(info TEST_EXECS   = $(TEST_EXECS))
#$(info TEST_LOGS    = $(TEST_LOGS))
#$(info TEST_LOGS    = $(TEST_LOGS))


define DAQ
import sys
import serial
import datetime

port = sys.argv[1]
baud = sys.argv[2]

sys.stderr.write("Starting data acquisition on %s with %s BAUD. Terminate it with CTRL-C\r\n" % (port, baud));
ser = serial.Serial(port, baud)
timeBegin = datetime.datetime.now()
while True:
   sys.stdout.write("%-15s: " % str(datetime.datetime.now() - timeBegin))
   sys.stdout.write(ser.readline())
endef
export DAQ


.PHONY:  \
   unittest \
   binary \
   download \
   daq \
   clean


binary: $(OUTDIR)/app.hex
	@ls $(OUTDIR)/app.hex


-include /usr/local/.sdkIsInstalled
/usr/local/.sdkIsInstalled:
	@mkdir -p $(@D) ; \
	./build/installSdk $(@)


device_port=out/devices/$(DEVICE)/port
.PHONY: $(device_port)
$(device_port):
	mkdir -p $(dir $(device_port)) ; \
	./build/detect-device $(DEVICE) > $(device_port)

download: $(device_port)

download_double=out/devices/$(DEVICE)/app.sha1
download: $(OUTDIR)/app.hex
	mkdir -p $(dir $(download_double)) ; \
	if ! cmp $(<).sha1 $(download_double) >/dev/null 2>&1 ; then \
		$(INSTALL_PATH_ARDUINO)/hardware/tools/avr/bin/avrdude \
		-C $(INSTALL_PATH_ARDUINO)/hardware/tools/avr/etc/avrdude.conf \
		-v \
		-p atmega328p \
		-c arduino \
		-b 57600 \
		-P $$(cat $(device_port)) \
		-D \
		-U flash:w:$(<):a \
		&& sha1sum $(<) > $(download_double) ;\
	else \
		echo "Device is up to date" ;\
	fi


.PRECIOUS: $(OUTDIR)/app.daq.log
daq: $(OUTDIR)/app.daq.log


$(OUTDIR)/app.daq.log: download
	mkdir -p $(@D) ; \
	python -u -c "$$DAQ" $$(cat $(device_port)) 57600 | tee $(@) ; test $${PIPESTATUS[0]} -eq 0


$(OUTDIR)/app.hex: $(OUTDIR)/app.elf
	mkdir -p $(@D) ; \
	$(INSTALL_PATH_ARDUINO)/hardware/tools/avr/bin/avr-objcopy \
	-O ihex \
	-R .eeprom \
	$(<) \
	$(@) \
	&& sha1sum $(@) > $(OUTDIR)/app.hex.sha1

$(OUTDIR)/app.elf: $(OBJECTS)
	mkdir -p $(@D) ; \
	$(INSTALL_PATH_ARDUINO)/hardware/tools/avr/bin/avr-g++ \
	-Wall -Wextra \
	-Os \
	-g \
	-flto -fuse-linker-plugin -Wl,--gc-sections \
	-mmcu=atmega328p \
	-o $(@) \
	$(^) \
	$(INSTALL_PATH_ARDUINO)/hardware/core-Arduino-Nano-ATmega328-16MHz.a \
	&& $(INSTALL_PATH_ARDUINO)/hardware/tools/avr/bin/avr-size \
	--mcu=atmega328p \
	-C $(@)

-include $(DEPS)
$(OUTDIR)/%.cpp.o: %.cpp
	mkdir -p $(@D) ; \
	$(INSTALL_PATH_ARDUINO)/hardware/tools/avr/bin/avr-gcc \
	-c \
	-MMD \
	-g \
	-Os \
	-w \
	-std=gnu++11 \
	-fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics  -flto \
	-mmcu=atmega328p \
	-DF_CPU=16000000L \
	-DARDUINO=10801 \
	-DARDUINO_AVR_NANO \
	-DARDUINO_ARCH_AVR \
	-I$(INSTALL_PATH_ARDUINO)/hardware/arduino/avr/cores/arduino \
	-I$(INSTALL_PATH_ARDUINO)/hardware/arduino/avr/variants/eightanaloginputs \
	-Iflavors/$(FLAVORDIR) \
	-include src/ardu.h \
	-o $(@) \
	$(<)


unittest: $(TEST_LOGS)


$(OUTDIR)/%.cpp.exe.log: $(OUTDIR)/%.cpp.exe
	mkdir -p $(@D) ; \
	./$(<) 2>&1 | tee $(@) ; test $${PIPESTATUS[0]} -eq 0

# I think this can be done with less lines using pattern rules. But I don't catch the idea now.
$(OUTDIR)/src/app_test.cpp.exe: $(TEST_OBJ_IUT)
$(OUTDIR)/src/packageA/packageA_test.cpp.exe: $(filter $(OUTDIR)/src/packageA/%,$(TEST_OBJ_IUT))
$(OUTDIR)/src/packageB/packageB_test.cpp.exe: $(filter $(OUTDIR)/src/packageB/%,$(TEST_OBJ_IUT))
$(OUTDIR)/src/packageC/packageC_test.cpp.exe: $(filter $(OUTDIR)/src/packageC/%,$(TEST_OBJ_IUT))
$(OUTDIR)/src/packageD/packageD_test.cpp.exe: $(filter $(OUTDIR)/src/packageD/%,$(TEST_OBJ_IUT))
$(OUTDIR)/src/packageE/packageE_test.cpp.exe: $(filter $(OUTDIR)/src/packageE/%,$(TEST_OBJ_IUT))

$(OUTDIR)/%_test.cpp.exe: $(OUTDIR)/%_test.cpp.o $(OUTDIR)/%.cpp.test.o
	mkdir -p $(@D) ; \
	gcc -g -o $(@) $(^)

-include src/test/Arduino_test.cpp.d
$(OUTDIR)/src/test/Arduino_test.cpp.o: src/test/Arduino_test.cpp
	mkdir -p $(@D) ; \
	gcc -c -g -x c++ -MMD -D__TEST__ -o $(@) -Iflavors/$(FLAVORDIR) -Isrc/test -include src/ardu.h $(<)

-include $(TEST_DEPS)
$(OUTDIR)/%_test.cpp.o: %_test.cpp
	mkdir -p $(@D) ; \
	gcc -c -g -x c++ -MMD -D__TEST__ -o $(@) -Iflavors/$(FLAVORDIR) -Isrc/test -include src/ardu.h $(<)

-include $(TEST_DEPS_IUT)
$(OUTDIR)/%.cpp.test.o: %.cpp
	mkdir -p $(@D) ; \
	gcc -c -g -x c++ -MMD -D__TEST__ -o $(@) -Iflavors/$(FLAVORDIR) -Isrc/test -include src/ardu.h $(<)

clean:
	@path_to_flavor=out/$$(echo $(FLAVOR) | sed 's/_/\//') ;\
	path_to_customer=out/$$(echo $(FLAVOR)| sed -r 's/(.+)_.+/\1/') ;\
	echo "Cleaning directory $$path_to_flavor" ;\
	rm -rf $$path_to_flavor ;\
	if [ -z $$(find $$path_to_customer -type f 2> /dev/null | head -1 || true) ]; then rm -rf $$path_to_customer ; fi ;\
	if [ -z $$(find out/ -type f 2> /dev/null | head -1 || true) ]; then rm -rf out/ ; fi
