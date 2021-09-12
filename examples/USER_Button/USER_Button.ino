/*
 * Simple Button LED Action
 *
 * USER LED blinks when you press the USSER button on your IOT2000
 *
 * Created by Dominik Reichl
 */
#include <IOT2000.h>

int blinkDelay = 1000;

void setup() {
  pinMode(USER_LED, OUTPUT);
  digitalWrite(USER_LED, HIGH);
	//Makes the USER button usable
  activateUserButton();
}

void loop() {
	//Does something when the button is pressed
  if (!readUserButton()) {
    digitalWrite(USER_LED, LOW);
    delay(blinkDelay);
    digitalWrite(USER_LED, HIGH);
    delay(blinkDelay);
    digitalWrite(USER_LED, LOW);
    delay(blinkDelay);
    digitalWrite(USER_LED, HIGH);
    delay(blinkDelay);
    digitalWrite(USER_LED, LOW);
    delay(blinkDelay);
    digitalWrite(USER_LED, HIGH);
  }
}
