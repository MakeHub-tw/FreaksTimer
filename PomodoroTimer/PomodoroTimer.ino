//#define DEBUG
#include <TimerOne.h>

// input definitions
#define encoderPinA  0
#define encoderPinB  1
#define buttonPin   10
#define buzzerPin   11

// totally 8 LEDs of the ring
const byte LEDs[] = {
  A5, A4, A3, A2, A1, A0, SCK, 17
};

// index to light the only one LED
byte indexLED = 0;

// minutes to count down
byte minutes = 0;
byte lastSetMinutes = 0;

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
    B00111111, B00000110, B01011011, B01001111, B01100110,
    B01101101, B01111101, B00000111, B01111111, B01101111
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

// limit the minimal minutes
void decreaseMinutes() {
  if (minutes > 0)
    minutes--;
}

// limit the maximal minutes
void increaseMinutes() {
  if (minutes < 99)
    minutes++;
}

void writeLEDs(byte state) {
  for (unsigned char i = 0; i < sizeof(LEDs); i++)
    digitalWrite(LEDs[i], state);
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

void onlyLED(byte num) {
  writeLEDs(LOW);
  digitalWrite(LEDs[num], HIGH);
}

void doCounting() {
  static byte ticks;

//  if (mode != COUNTING) return;

  switch (ticks++) {
    case 0:
      analogWrite(buzzerPin, 2);
      break;
    case 1:
      analogWrite(buzzerPin, 0);
      break;
    case 10:
      onlyPrevLED();
      ticks = 0;
  }
}

void doEncoder() {
  if (mode == STANDBY) {
    if (digitalRead(encoderPinA) == digitalRead(encoderPinB))
      decreaseMinutes();
    else
      increaseMinutes();
  }
}

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
    
  pinMode(2, OUTPUT); 
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  for (byte i = 0; i < sizeof(LEDs); i++)  {
    pinMode(LEDs[i], OUTPUT);
  }

  pinMode(buzzerPin, OUTPUT);

  pinMode(buttonPin,   INPUT_PULLUP);
  pinMode(encoderPinA, INPUT_PULLUP);
  pinMode(encoderPinB, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(encoderPinA), doEncoder, FALLING);

  Timer1.initialize(100000);
  Timer1.attachInterrupt(doCounting);

#ifdef DEBUG
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB, on LEONARDO, MICRO, YUN, and other 32u4 based boards.
  }
#endif
}

void loop()
{
  static byte lastButtonState = HIGH;
  static byte buttonState;                    // the current reading from the input pin

  static unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
  static unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers
 
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
            lastSetMinutes = minutes;
            mode = COUNTING;
            break;
      
          case COUNTING:
            mode = STANDBY;
            break;
      
          case ALERTING:
            minutes = lastSetMinutes;
            mode = STANDBY;
            break;
        }
      }
    }
  }

  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState = reading;

  // house keeping the nixie tube
  displayDigit(0, minutes % 10);
  delay(1);
  displayDigit(1, minutes / 10);
  delay(1);
}

