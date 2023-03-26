MAKEFLAGS += --no-builtin-rules
.SUFFIXES:

settings=makew_settings.mk

define HELP
Mini build system - Part of Simulation game of Continuous Integration of Automotive Software powered by Arduino.

Possible commands resp. make goals:

 ./makew unittest      # Build and execute unittests of all components.

 ./makew binary        # Build the executable binary for the target device.

 ./makew clean         # Remove all build artifacts. Next build will be a full one.

 ./makew download      # Build (if necessary), then download (aka flash) and run on the embedded device

 ./makew daq           # Doing data acquisition over COM port. Exit with CTRL-C. If necessary build, download are done automatically

 ./makew help          # Display this help screen

                       # Hint: For download and/or daq you need to have the driver installed. Local admin permissions are necessary for that.
                       # For further instruction see ...
                       #    /usr/local/Arduino/drivers/CH34x/README.txt


In addition, the file $(settings) makes following variables available you can use to influence the build:

             FLAVORS=<regex>                     # Filter applied to flavors, regular expression
                                                 # Examples:
                                                 #   FLAVORS=M_a
                                                 #   FLAVORS=M_[beh-j]

                                                 # Default is, so if omitted: FLAVOR=M_a

             UNITS=<regex>                       # Filter applied to software UNITS (components, packages, etc), regular expression
                                                 # Examples:
                                                 #   UNITS=A.+
                                                 #   UNITS=[AC-Z][135-10]

                                                 # Defaults are, so if omitted: FLAVORS=.+ UNITS=.+
                                                 # UNITS only makes sense only in conjunction with target unittest

             DEVICE=<position>                   # Example:
                                                 #    DEVICE=2
                                                 # Default is, so if omitted: DEVICE=1

endef
export HELP

.PHONY: help
help: makew.bat
	@echo "$$HELP"

makew.bat:
	@cp build/template_makew_bat $(@)

-include $(settings)
$(settings):
	@echo 'FLAVORS=M_a'  > $(@) ;\
	 echo 'UNITS=.+'   >> $(@) ;\
	 echo 'DEVICE=1'   >> $(@) ;\
	 echo "Created settings file containing default build parameters: $(@)" ;\

ifneq ($(MAKECMDGOALS),)
ifneq ($(MAKECMDGOALS),help)

ifndef UNITS
UNITS=.+
endif

ifneq ($(MAKECMDGOALS),unittest)
UNITS:=.+
endif
export UNITS


ifndef FLAVORS
FLAVORS=.+
endif


ifndef DEVICE
DEVICE=1
endif
export DEVICE

buildlog=build.log

%:
	@mkdir -p out/ ;\
	for f in $$(find flavors -name config.h | sed -r 's/flavors\/(.+)\/config.h/\1/' | sed 's/\//_/' | grep -E '$(FLAVORS)') ; do \
	   flavorDir=out/$$(echo $$f | sed 's/_/\//') ;\
	   mkdir -p $$flavorDir ;\
	   echo "**** STARTING NEW BUILD AT $$(date) ******" | tee -a $$flavorDir/$(buildlog) ;\
	   $(MAKE) -f build/buildSingleFlavor.mk $(@) $(MFLAGS) FLAVOR=$$f --no-print-directory 2>&1 | tee -a $$flavorDir/$(buildlog) ; test $${PIPESTATUS[0]} -eq 0 ;\
	done 2>&1 | tee -a out/$(buildlog) ; test $${PIPESTATUS[0]} -eq 0

endif # help
endif # -empty-
