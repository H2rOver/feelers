/* This sketch demonstrates the function of the Solarbiotic digital feelers
 *    Connect "-" to ground
 *    Connect "S" to pin3
 *    Connect an LED to pin2
 * The LED lights up when contact is made
 * The other connections are unnecessary if you use an internal pullup resistor on the arduino
 */

#include <EEPROM.h>

int LED = 2, FEELER = 3;

// the setup routine runs once when you press reset:
void setup() {
  pinMode(LED, OUTPUT);
  pinMode(FEELER, INPUT_PULLUP);  //uses internal pullup resistor
}

// the loop routine runs over and over again forever:
void loop() {
  int feeler_contact = 0;
  //active low signal from feeler
  feeler_contact = not(digitalRead(FEELER));
  digitalWrite(LED, feeler_contact);
}
