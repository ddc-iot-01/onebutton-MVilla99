/*
 * Project: Using OneButton library
 * Description: Introduct Students to OneButton Library using a button and the serial monitor
 * Author: Mauricio Villa
 * Date:3-3-20 
 */

#include <OneButton.h>
//# means include in file (for libraries)
// can do includes with ("") or (<>)
// Setup OneButton on pin 23
OneButton button1(23, false);

int ledPin = 5;
int ledPin1 = 6; 
int ledPin2 = 7;
int buttonState = LOW;
int flash = LOW;

void setup() {
  
Serial.begin(9600);
while(!Serial);
Serial.println ();
// Link oneButton library to functions click1, doubleclick1, longPressStart1
button1.attachClick(click1);
button1.attachDoubleClick(doubleclick1);
//button1.attachLongPressStart(longPressStart1);
//button1.attachLongPressStop(longPressStop1);
button1.setClickTicks(250);
button1.setPressTicks(1000);
 if (Serial) Serial.println ("Starting One Button ...");
pinMode(ledPin, OUTPUT);
} 

void loop() {
  // keep watching the push buttons:
  button1.tick();
  if (buttonState == LOW) {
    digitalWrite(ledPin, LOW);
  }
    else 
    { 
      digitalWrite(ledPin, HIGH);
    }
    if (flash == LOW){
      digitalWrite(ledPin, LOW);
    }
    else
    { 
      digitalWrite(ledPin, HIGH);
      delay(50);
      digitalWrite(ledPin, LOW);
      delay(50);
    }
}
    // loop

// This function will be called when the button1 was pressed 1 time.
void click1() {
  Serial.println("Button 1 click");
  buttonState = !buttonState;
  Serial.print("buttonState =");
  Serial.println (buttonState);
//change and print buttonState
  
} // click1 

// This function will be called when the button1 was pressed 2 times in a short timeframe.
void doubleclick1() {
  Serial.println("Button 1 doubleclick.");
  flash = !flash;
  Serial.print("flash = ");
  Serial.println(flash);
// change state of flash and print
} // doubleclick1


// This function will be called once, when the button1 is pressed for a long time.
//void longPressStart1() {
// print longPress
// } // longPressStart1
