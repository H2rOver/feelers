#include <MotorControl.h>
#include <PinDeclarations.h>

MotorControl Red = MotorControl();

int feeler_contact_L = 0;
int feeler_contact_R = 0;

void setup() {
  Serial.print("begin routine");
  // set all the motor control pins to outputs  
  pinMode(LeftFeeler, INPUT_PULLUP);
  pinMode(RightFeeler, INPUT_PULLUP);

  Red.motorForward(255);
}

void loop() {

  //active low inputs
  feeler_contact_L = not(digitalRead(LeftFeeler));
  feeler_contact_R = not(digitalRead(RightFeeler));

  if(feeler_contact_L || feeler_contact_R)
  {
    Red.motorOff();
   }
  else
  {
    Red.motorForward(255);
  }
}
