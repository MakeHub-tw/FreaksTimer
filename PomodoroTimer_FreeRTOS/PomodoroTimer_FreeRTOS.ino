#include <util/atomic.h>
#include <avr/sleep.h>

#include <Arduino_FreeRTOS.h>
#include <TimerOne.h>

//#define DEBUG
//#define BASE_16

// input definitions
#define encoderPinA  0
#define encoderPinB  1
#define buttonPin   10
#define buzzerPin   11

// totally 8 LEDs of the ring
const byte LEDs[] = {
  17, A5, A4, A3, A2, A1, A0, SCK
};

// index to light the only one LED
byte indexLED = 0;

volatile byte seconds = 0;
// minutes to count down
volatile int  minutes = 0;
int lastSetMinutes = 0;

// system modes
enum systemMode {
  STANDBY, 
  COUNTING,
  ALERTING
};

volatile systemMode mode = STANDBY;

void lightNumber(byte num) {
  // PIN 9, 8, 7, 6, 5, 4, 3, 2 map to 8 binary digits
  static const byte numbers[] = {
    B00111111, B00000110, B01011011, B01001111, B01100110,  // 0 ~ 4
    B01101101, B01111101, B00000111, B01111111, B01101111,  // 5 ~ 9
    B01110111, B01111100, B00111001, B01011110, B01111001, B01110001  // A ~ F
  };

  byte number = numbers[num];

  for (byte pin = 2; pin < 10; pin++) {
    digitalWrite(pin, number & 0x01);
    number = number >> 1;
  }
}

void displayDigit(byte digit, byte num) {
  // turn off all first
  for (unsigned char pin = 2; pin < 10; pin++)
    digitalWrite(pin, LOW);

  // activate the corresponding digit
  if (digit == 0) {
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
  } else {
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
  }

  // turn on
  lightNumber(num);
}

void writeLEDs(byte state) {
  for (byte i = 0; i < sizeof(LEDs); i++)
    digitalWrite(LEDs[i], state);
}

// turn off all but the indexLED one
void onlyLED() {
  writeLEDs(LOW);
  digitalWrite(LEDs[indexLED], HIGH);
}

void onlyPrevLED() {
  digitalWrite(LEDs[indexLED--], LOW);
  indexLED = indexLED & 7;
  digitalWrite(LEDs[indexLED], HIGH);
}

void onlyNextLED() {
  digitalWrite(LEDs[indexLED++], LOW);
  indexLED = indexLED & 7;
  digitalWrite(LEDs[indexLED], HIGH);  
}

// limit the minimal minutes
void decreaseMinutes() {
  if (minutes > 0) {
    minutes--;
    seconds = 0;
    lastSetMinutes = minutes;
    onlyPrevLED();
  }
}

// limit the maximal minutes
void increaseMinutes() {
#ifdef BASE_16
  if (minutes < 255) {
#else
  if (minutes < 99) {
#endif
    minutes++;
    seconds = 0;
    lastSetMinutes = minutes;
    onlyNextLED();
  }
}

void doCounting() {
  static byte ticks = 0;

  if (mode == COUNTING) {
    switch (ticks++) {
      case 0 :
        analogWrite(buzzerPin, 2);  // start small ticktock
        break;
      case 1 :
        analogWrite(buzzerPin, 0);  // stop ticktock
        break;
      case 19 :
        ticks = 0;      // divided by 20
        onlyPrevLED();
        if (seconds++ == 59) {
          seconds = 0;  // divided by 60
          minutes--;  // decrease minutes
        }
    }

    if (minutes == 0) {
      mode = ALERTING;
    }
  } else if (mode == ALERTING) {
    ticks++;

    if (ticks % 2) {
      analogWrite(buzzerPin, 255);
      writeLEDs(HIGH);
    } else {
      analogWrite(buzzerPin, 0);
      writeLEDs(LOW);
    }

    if (ticks == 20) {
      ticks = 0;      // divided by 20
      if (seconds++ == 59) {
        seconds = 0;  // divided by 60
        minutes--;    // decrease minutes
      }
    }

    if (minutes < 0) {
      minutes = lastSetMinutes;
      mode = STANDBY;
    }
  }
}

void doEncoder() {
  if (mode == STANDBY) {
    if (digitalRead(encoderPinA) == digitalRead(encoderPinB)) {
      decreaseMinutes();
    } else {
      increaseMinutes();
    }
  }
}


void TaskButton( void *pvParameters )
{
  (void) pvParameters;

  static byte lastButtonState = HIGH;
  static byte buttonState;                    // the current reading from the input pin

  static unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
  static unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

  for (;;) // A Task shall never return or exit.
  {
    int reading = digitalRead(buttonPin);

    // check to see if you just pressed the button
    // (i.e. the input went from LOW to HIGH),  and you've waited
    // long enough since the last press to ignore any noise:

    // If the switch changed, due to noise or pressing:
    if (reading != lastButtonState) {
      // reset the debouncing timer
      lastDebounceTime = millis();
    }

    if ((millis() - lastDebounceTime) > debounceDelay) {
      // whatever the reading is at, it's been there for longer
      // than the debounce delay, so take it as the actual current state:

      // if the button state has changed:
      if (reading != buttonState) {
        buttonState = reading;

        // only toggle the LED if the new button state is LOW
        if (buttonState == LOW) {
          switch (mode) {
            case STANDBY:
              mode = COUNTING;
              writeLEDs(HIGH);
              break;

            case COUNTING:
              mode = STANDBY;
              writeLEDs(HIGH);
              break;

            case ALERTING:
              mode = STANDBY;
              digitalWrite(buzzerPin, LOW);
              writeLEDs(LOW);
              minutes = lastSetMinutes;
              break;
          }
        }
      }
    }

    // save the reading.  Next time through the loop,
    // it'll be the lastButtonState:
    lastButtonState = reading;

    vTaskDelay( 1 );
  }
}

void setup()
{
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);

  for (byte i = 0; i < sizeof(LEDs); i++)  {
    pinMode(LEDs[i], OUTPUT);
  }

  pinMode(13, OUTPUT);  // digit 1
  pinMode(12, OUTPUT);  // digit 0
    
  pinMode(2, OUTPUT);   // a
  pinMode(3, OUTPUT);   // b
  pinMode(4, OUTPUT);   // c
  pinMode(5, OUTPUT);   // d
  pinMode(6, OUTPUT);   // e
  pinMode(7, OUTPUT);   // f
  pinMode(8, OUTPUT);   // g
  pinMode(9, OUTPUT);   // p

  pinMode(buttonPin,   INPUT_PULLUP);
  pinMode(encoderPinA, INPUT_PULLUP);
  pinMode(encoderPinB, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(encoderPinA), doEncoder, FALLING);

  Timer1.initialize(50000);           // 0.05 second per tick
  Timer1.attachInterrupt(doCounting);

  xTaskCreate(
    TaskButton
    ,  (const portCHAR *)"Button"     // A name just for humans
    ,  128  // This stack size can be checked & adjusted by reading the Stack Highwater
    ,  NULL
    ,  2  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
    ,  NULL );

#ifdef DEBUG
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB, on LEONARDO, MICRO, YUN, and other 32u4 based boards.
  }
#endif

  // Leonardo would write pin 17 HIGH after setup by itself
}

void loop()
{
  // housekeeping of the nixie tube
#ifdef BASE_16
  displayDigit(0, minutes % 16);
#else
  displayDigit(0, minutes % 10);
#endif
  delay(1);

#ifdef BASE_16
  displayDigit(1, minutes / 16);
#else
  displayDigit(1, minutes / 10);
#endif
  delay(1);
}

