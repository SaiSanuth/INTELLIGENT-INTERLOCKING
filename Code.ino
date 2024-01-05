//Including the header files used for the project
#include <HX711_ADC.h>
#include<Servo.h>

HX711_ADC LoadCell(4, 5); // parameters: dt pin 4, sck pin 5;
Servo S1;

 void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);
  LoadCell.begin(); // start connection to HX711
  LoadCell.start(2000); // load cells gets 2000ms of time to stabilize
  LoadCell.setCalFactor(1000.0); // calibration factor for load cell 
  S1.attach(9);

 
 
}

void loop() {
  LoadCell.update(); // retrieves data from the load cell
  float i = LoadCell.getData(); // get output value
  int x = Serial.read();
  if(x<=2000){ //if the value of i is less than 2000 then it performs the below action
  digitalWrite(LED_BUILTIN, LOW);

  S1.write(0);

  }
  else if(x>2000){ 
  digitalWrite(LED_BUILTIN, HIGH);

  S1.write(180);

  }

}

