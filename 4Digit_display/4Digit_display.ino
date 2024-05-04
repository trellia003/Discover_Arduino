/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-tm1637-4-digit-7-segment-display
 */

#include <TM1637Display.h>

// define the connections pins
#define CLK 8
#define DIO 7

// create a display object of type TM1637Display
TM1637Display display = TM1637Display(CLK, DIO);

// an array that sets individual segments per digit to display the word "dOnE"
const uint8_t done[] = {
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,         // d
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F, // O
  SEG_C | SEG_E | SEG_G,                         // n
  SEG_A | SEG_D | SEG_E | SEG_F | SEG_G          // E
};

// degree celsius symbol
const uint8_t celsius[] = {
  SEG_A | SEG_B | SEG_F | SEG_G,  // Degree symbol
  SEG_A | SEG_D | SEG_E | SEG_F   // C
};

void setup() {
  display.clear();
  display.setBrightness(7); // set the brightness to 7 (0:dimmest, 7:brightest)
}

void loop() {
  // show counter 0-9
  int i;
  for (i = 0; i < 10; i++) {
    display.showNumberDec(i);
    delay(500);
  display.clear();
  }

  display.showNumberDec(-91);             // displayed _-91
  delay(2000);
  display.clear();

  display.showNumberDec(-109);            // displayed -109
  delay(2000);
  display.clear();

  display.showNumberDec(21, false);       // displayed __21
  delay(2000);
  display.clear();

  display.showNumberDec(21, true);        // displayed 0021
  delay(2000);
  display.clear();

  display.showNumberDec(28, false, 2, 1); // displayed _28_
  delay(2000);
  display.clear();

  display.showNumberDec(-9, false, 3, 0); // displayed _-9_
  delay(2000);
  display.clear();

  // displayed 15:30
  display.showNumberDecEx(1530, 0b11100000, false, 4, 0);
  delay(2000);
  display.clear();

  // displayed 23°C
  int temperature = 23; // or read from temperature sensor
  display.showNumberDec(temperature, false, 2, 0);
  display.setSegments(celsius, 2, 2);
  delay(2000);
  display.clear();

  // displayed letters: dOnE
  display.setSegments(done);
  delay(2000);
  display.clear();
}
