// **Disclaimer:** This electronic tutorial is provided for informational purposes only. The author disclaims all liability for any damage or loss resulting from its use.


/*

Script developed by Quentin Poret & Christophe
using Tinkercad software.

The purpose of this script is to turn off the backlight of a 16x2 LCD display using a button.

-----------------------------
Source : 

//www.elegoo.com
//2016.12.9
------------------
LCD TEXT FROM: http://www.arduino.cc/en/Tutorial/LiquidCrystal

  LiquidCrystal Library - Hello World

 Demonstrates the use of a 16x2 LCD display. The LiquidCrystal
 library is compatible with all LCD displays that use the
 Hitachi HD44780 driver, identifiable by their 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and displays the time.

 Library originally added on 18 Apr 2008
 by David A. Mellis
 Library modified on 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 Example added on 9 Jul 2009
 by Tom Igoe
 Modified on 22 Nov 2010
 by Tom Igoe

 */


// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
// LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int buttonPin = 3;  // Turns on the display
const int backlightPin = 4;  // Drives the backlight transistor
bool backlightOn = false;

int buttonState = 0;
int previousButtonState = 0;


void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
 // lcd.nobacklight();
  // Print a message to the LCD.
  lcd.print("Hello, World!");
  pinMode(buttonPin, INPUT);
  pinMode(backlightPin, OUTPUT);
}


void loop() {
  
  
 // LCD TEXT CODE // 
  
  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);


  // Display backlight code //
 

 buttonState = digitalRead(buttonPin);
if ((buttonState == HIGH) && (previousButtonState == LOW)) {
  // Toggle the backlight
  if (backlightOn) {
    // If the backlight is currently on, turn it off
    digitalWrite(backlightPin, LOW);
    backlightOn = false; // Update the flag to indicate that the backlight is off
  } else {
    // If the backlight is currently off, turn it on
    digitalWrite(backlightPin, HIGH);
    backlightOn = true; // Update the flag to indicate that the backlight is on
  }
  delay(1000); // Delay to debounce the button press
}


}

