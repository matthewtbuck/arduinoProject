/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch uses a keypad in order to input a password into an LCD

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 3 Dec 2020

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// Allows it to use library code for both the LCD as well as the keypad:
#include <LiquidCrystal.h>
#include <Keypad.h>

char* password = "889246";  // This is the password that is being prompted
int position = 0; //Establishes an integer at the 0 position
const byte ROWS = 4; //Tells the circuit there are 4 rows on the keypad
const byte COLS = 4; //Tells the circuit there are 4 columns on the keypad
/**/
char keys[ROWS][COLS] = { //This entire set establishes which keys are where on the keypad
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};

/**/
byte rowPins[ROWS] = { 7, 6, 5, 4 }; //Pins that the rows are connected to on the arduino
byte colPins[COLS] = { 3, 2, 1, 0 }; //Pins that the columns are connected to on the arduino
/**/
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //Tells the circuit to map the keys to each space established
/**/

// Pins connecting arduino to breadboard, which is connected to LCD
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

void setup() {
  // Amount of columns and rows on the LCD:
  lcd.begin(16, 2);
  // This is what shows up on the LCD.
  lcd.print("Passcode?");
}

void loop() {
  // Starts the cursor on the first column, second row
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
char key = keypad.getKey(); //Arduino recognizes key that is pressed and saves as a character value
if (key == '*' || key == '#') //If either the * key or # key are pressed, it will display as incorrect
{
position = 0;
lcd.print("Incorrect");
}
if (key == password[position]) //If the correct password is input, this will move on to the next step in the code
{
position ++; //Adds to the integer "position."
}
if (position == 6) //If the correct password is entered, the position integer will match what it is on this line.
{
lcd.println("Success!");//If the above integers matched, the LCD will print "Success!"
}
delay(100); //Delays message by 100 milliseconds
}
 