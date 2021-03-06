#include <Arduino.h>

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

/*Buttons should be driven with a pull-up resistor
 * so the switch should pull the pin to ground momentarily
 * On a high -> low transition, the button press logic will
 * execute
 */

 //Pin Assignment
 //Button 1 - Pin 3 Solid colors
 //Button 2 - Pin 4 Motion effects
 //Pixel data out - Pin 6
 //Ground - pin G
 //+5V in - Pin BAT
 //Resistor on pixeld data line
 //Capacitor between Vin and Ground
 //Buttons between button pins and ground

const int BUTTON1_PIN = 3;
const int BUTTON2_PIN = 4;

const int PIXEL_PIN = 6;
const int PIXEL_COUNT = 60;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

int caseNum = 200; //initially set to off

unsigned long displayTimer; //Used for timing the light motion

//sleep timer
unsigned long sleepTimer;
const unsigned long sleepTimerLength = 3600000UL; //milliseconds

//Color constants
//Calculated with RGB = R*256*256 + G*256 + B
const uint32_t FULL_WHITE = 16777215; //R 255, G 255, B 255
const uint32_t Q3_WHITE = 12566463; //R 191, G 191, B 191
const uint32_t Q2_WHITE = 8355711; //R 127, G 127, B 127
const uint32_t Q1_WHITE = 4144959; //R 63, G 63, B 63
const uint32_t OFF = 0; //R 0, G 0, B 0
const uint32_t RED = 16711680; //R 255, G 0, B 0
const uint32_t ORANGE = 16744192; //R 255, G 123, B 0
const uint32_t YELLOW = 16776960; //R 255, G 255, B 0
const uint32_t GREEN = 65280; //R 0, G 255, B 0
const uint32_t TEAL = 65535; //R 0, G 255, B 255
const uint32_t BLUE = 255; //R 0, G 0, B 255
const uint32_t PURPLE = 8323327; //R 123, G 0, B 255
uint32_t colorStorage; // = RandomColor();

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code
  randomSeed(analogRead(0));

  colorStorage = RandomColor();

  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);
  strip.begin();
  strip.show();
}

unsigned long Button1Time;

void loop() {
  bool button1State = digitalRead(BUTTON1_PIN);
  unsigned long curTime = millis();

  if (!button1State) {
    if (curTime - button1Time > 200UL) {
      // Change display
    }
  } else {
    Button1Time = curTime;
  }
}
