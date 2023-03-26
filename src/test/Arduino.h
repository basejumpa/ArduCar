#ifndef Arduino_h
#define Arduino_h


#define HIGH 0x1
#define LOW  0x0

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

#define UINT8_MAX   (255)

typedef unsigned char uint8_t;

typedef char* (*getNextLine_t)(void);

typedef struct {
	
	struct {
		uint8_t mode;
		uint8_t value;
	} D[13];
	
	struct {
		uint8_t mode;
		uint8_t value;
	} A[7];
	
	struct {
		getNextLine_t getNextLine; 
		unsigned long baud;
	} Serial;
	
} arduino_t;
extern arduino_t arduino;


void setup(void);
void loop(void);

void pinMode(uint8_t, uint8_t);

void digitalWrite(uint8_t, uint8_t);
int digitalRead(uint8_t);

void analogWrite(uint8_t, int);
int analogRead(uint8_t);

unsigned long millis(void);


class Serial_mock {
   public:
      void begin(unsigned long);
	  void print(const char*, ...);
	  void println(const char*, ...);
};

extern Serial_mock Serial;

#endif /* Arduino_h */
