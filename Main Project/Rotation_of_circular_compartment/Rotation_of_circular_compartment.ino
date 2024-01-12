#include <Stepper.h>

int motorSpeed = 10;
Stepper myStepper(2048, 8, 10, 9, 11);

void setup() {
  // put your setup code here, to run once:
  myStepper.setSpeed(motorSpeed);
  Serial.begin(9600);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  int number; // Variable to store the user's number
  int count;
  int c,c2,c1; // Variable to store the calculation result

  Serial.println("Please enter the compartment number: "); // Prompt the user for input

  while (!Serial.available()) {
    // Wait until the user enters a number
  }

  // Read the number entered by the user
  number = Serial.parseInt();

  c = 4 - number;
  if (c > 0) {
    count = number;
   c2=count;
    while (count > 0) {
      myStepper.step(256);
      delay(1000);
      count = count - 1;
    }
    while (c2 > 0) {
      myStepper.step(-256);
      delay(1000);
      c2= c2 - 1;
    }

  }
  else {
    count = 8 - number;
   c1=count;
    while (count > 0) {
      myStepper.step(-256);
      delay(1000);
      count = count - 1;
    }
delay(1000);
while(c1>0)
{
      myStepper.step(256);
      delay(1000);
      c1= c1- 1;
}
  }

  // Perform any further operations with the number as needed

  delay(1000);
}
