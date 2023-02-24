/*
  Data Display Screen
*/

#include <LiquidCrystal.h>          //the liquid crystal library contains commands for printing to the display

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);   // tell the RedBoard what pins are connected to the display

void setup() {

  lcd.begin(16, 2);                 //tell the lcd library that we are using a display that is 16 characters wide and 2 characters high
  lcd.clear();                      //clear the display
}

void loop() {

  lcd.setCursor(0, 0);              //set the cursor to the 0,0 position (top left corner)
  lcd.print("Annual inc in CO2:");       //print starting at that position

  lcd.setCursor(0, 1);              //move the cursor to the first space of the bottom row
  lcd.print("1960: 1.35");

  delay(1000);
  lcd.clear();

  lcd.setCursor(0, 0);              //set the cursor to the 0,0 position (top left corner)
  lcd.print("nual inc in CO2:");       //print starting at that position

  lcd.setCursor(0, 1);              //move the cursor to the first space of the bottom row
  lcd.print("2021: 2.38");

  delay(1000);
}