/* This sketch demonstrates the function of the Solarbiotic digital feelers
 *  Left feeler:
 *    Connect "-" to ground
 *    Connect "S" to pin3
 *    Connect an LED to pin2
 *  Right feeler:
 *    Connect "-" to ground
 *    Connect "S" to pin5
 *    Connect an LED to pin4
 * The LED lights up when contact is made
 * The other connections are unnecessary if you use an internal pullup resistor on the arduino
 */

#include <EEPROM.h>

int LED_L = 2, FEELER_L = 3;
int LED_R = 4, FEELER_R = 5;

// the setup routine runs once when you press reset:
void setup() {
  pinMode(LED_L, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(FEELER_L, INPUT_PULLUP);  //uses internal pullup resistor
  pinMode(FEELER_R, INPUT_PULLUP);  //uses internal pullup resistor
}

// the loop routine runs over and over again forever:
void loop() {
  int feeler_contact_L = 0;
  int feeler_contact_R = 0;
  //active low signal from feelers
  //left feeler
  feeler_contact_L = not(digitalRead(FEELER_L));
  digitalWrite(LED_L, feeler_contact_L);
  //right feeler
  feeler_contact_R = not(digitalRead(FEELER_R));
  digitalWrite(LED_R, feeler_contact_R);
}
