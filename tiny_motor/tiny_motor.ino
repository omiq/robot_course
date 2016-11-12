/*

 In this example we pulse a tiny motor.

 We can only do this safely because it IS tiny!

 If in doubt, follow one of the later examples. 

 You do not want to fry your kit.

 The analogWrite() function outputs PWM, 
 A PWM pin is usually marked with a '~'

 We are using pin 9 for this example.

 */

int pin = 9;           // the PWM pin the motor is attached to
int power = 0;         // how much power to send


// set things up ...
void setup() {

  // start the serial connection
  Serial.begin(115200);

  // declare pin 9 to be an output:
  pinMode(pin, OUTPUT);
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
        
        // set the power of pin 9:
        analogWrite(pin, power);  

    }
  }
}
