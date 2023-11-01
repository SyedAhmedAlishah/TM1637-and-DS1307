/*
This Code was generateed by Syed Ahmad Ali on 29 Oct, 2023, 
Pins Connection for tested code. 
Arduino (Nano)       |   DS1307 module     | TM1637 Display
     5V              |      Vcc            |      Vcc
     GND             |      GND            |      GND
     D3              |       -             |      CLK
     D4              |       -             |      DIO
     A4              |      SDA            |       - 
     A5              |      SCL            |       -

Libraries:
DS1307 sensor library uRTCLib by Naguissa (v 6.6.1)
TM1637 by Avishay Orpaz (v 1.2.0)
*/

// Libraries for DS1307 and TM1637 Moddules
#include "Arduino.h"

#include "uRTCLib.h"
#include <TM1637Display.h>

#define CLK 3    // Digital pin connected to the CLK of TM1637 display 
#define DIO 4    // Digital pin connected to the DIO of TM1637 display 

// Create a display object of TM1637 segment display
TM1637Display display = TM1637Display(CLK, DIO);

// Create a rtc object of uRTCLib;
uRTCLib rtc(0x68);


char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

String clock; // Variable to store combine string of hours and minutes

void setup() {
  Serial.begin(9600);
  display.setBrightness(5); // Set brightness between 0 (min) and 7 (max)
  delay(3000); // wait for console opening

  // Initializing I2C communication
  URTCLIB_WIRE.begin();

  // Comment out below line once you set the date & time.
  // Following line sets the RTC with an explicit date & time
  // for example to set January 13 2022 at 12:56 you would call:
  //rtc.set(0, 28, 12, 1, 29, 10, 23);
  // rtc.set(second, minute, hour, dayOfWeek, dayOfMonth, month, year)
  // set day of week (1=Sunday, 7=Saturday)
}

void loop() {
  rtc.refresh();  // Refreshing the RTC data to rtc object

  // Serial.print("Current Date & Time: ");
  // Serial.print(rtc.year());
  // Serial.print('/');
  // Serial.print(rtc.month());
  // Serial.print('/');
  // Serial.print(rtc.day());

  // Serial.print(" (");
  // Serial.print(daysOfTheWeek[rtc.dayOfWeek()-1]);
  // Serial.print(") ");

  // Serial.print(rtc.hour());
  // Serial.print(':');
  // Serial.print(rtc.minute());
  // Serial.print(':');
  // Serial.println(rtc.second());
  
  clock = String(rtc.hour()) + String(rtc.minute()); // Converting int type return of .hour and .minute into string and concatenate

  display.showNumberDecEx(clock.toInt(), 0b11100000, true, 4, 0); // True for displaying colon of display segment
  delay(1000);
  display.clear();

  delay(100);
}