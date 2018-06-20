/*
 * Simple Button LED Action
 *
 * USER LED blinks when you press the USSER button on your IOT2000
 *
 * Created by Dominik Reichl
 */
#include <IOT2000.h>

int blinkTime=1000;

void setup() {
  pinMode(USER_LED,OUTPUT);
  digitalWrite(USER_LED,HIGH);
	//Makes USER button usable
  activateUserButton();
}

void loop() {
	//Does something when the button is pressed
  if(!readUserButton()){
    digitalWrite(USER_LED,LOW);
    delay(blinkTime);
    digitalWrite(USER_LED,HIGH);
    delay(blinkTime);
    digitalWrite(USER_LED,LOW);
    delay(blinkTime);
    digitalWrite(USER_LED,HIGH);
    delay(blinkTime);
    digitalWrite(USER_LED,LOW);
    delay(blinkTime);
    digitalWrite(USER_LED,HIGH);
  }
}
