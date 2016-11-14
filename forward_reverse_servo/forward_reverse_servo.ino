/*

 In this sketch we control a servo.

 We use the Servo library and are using 
 pin 9 for this example.

 */

// Using the servo library to make it easy
#include <Servo.h>     

int pin = 9;           // the PWM pin the servo is attached to
int power = 0;         // how much power to send

Servo myservo;         // this will be our servo

// set things up ...
void setup() {

  // start the serial connection
  Serial.begin(115200);

  // declare pin 9 to be an output:
  pinMode(pin, OUTPUT);

  // tell the servo it is on pin 9
  myservo.attach(9);
  
}

// keep doing this forever:
void loop() {

  // play with the power setting to see
  // the effects
  while (Serial.available() > 0) {

    // look for the next power number in the serial monitor
    // turn it into an integer and place in our power variable:
    int power = Serial.parseInt();
 
    // look for the newline
    if (Serial.read() == '\r') {

        // report back the number we were provided:
        Serial.print(power);

        // output text to say we got it
        Serial.println(" - Roger!");
        
        // set the power on the servo:
        myservo.write(power); 

    }
  }
}
