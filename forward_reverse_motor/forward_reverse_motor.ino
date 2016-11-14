/*

 In this sketch we control a motor using
 the popular L293D H-Bridge chip.

 We use pins 6, 9 and 11 for this example.

 */

// Using the servo library to make it easy
#include <Servo.h>     

// input pins
int pin1 = 9;          // the pins the inputs are attached to
int pin2 = 6;

// set on/off and speed
int enablepin = 11;

int power = 0;         // how much power to send

// set things up ...
void setup() {

  // start the serial connection
  Serial.begin(115200);

  // declare both pins to be output:
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);

  // enable pin is also output
  pinMode(enablepin, OUTPUT);

}

// keep doing this forever:
void loop() {

  // play with the power setting to see
  // the effects
  while (Serial.available() > 0) {

    // F or R
    String direction = Serial.readStringUntil(',');

    // look for the next power number in the serial monitor
    // turn it into an integer and place in our power variable:
    int power = Serial.parseInt();
 
    // look for the newline
    if (Serial.read() == '\r') {

        // report back the number we were provided:
        Serial.print(power);
      
        if(direction == "f") {
          digitalWrite(pin1, LOW);
          digitalWrite(pin2, HIGH);

          // set the speed
          analogWrite(enablepin, power);

                    
        } else {
          digitalWrite(pin1, HIGH);
          digitalWrite(pin2, LOW);
          
          // set the speed
          analogWrite(enablepin, power);
        }

        
        // output text to say we got it
        Serial.println(" - Roger!");
    }
  }
}
