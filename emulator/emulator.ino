/*

Open Laundry API Washing Machine Emulator.

Sends data received from serial to PWM

created 11 November 2012
by suda (github.com/suda) - OpenLaundryAPI team (github.com/OpenLaundryAPI)

*/
int pwmPin = 9; // output pin supporting PWM

void setup()
{
  // initialize serial:
  Serial.begin(9600);
  
  pinMode(pwmPin, OUTPUT); // sets the pin as output
}

void loop()
{
  while (Serial.available() > 0) {
    int value = Serial.parseInt();
    value = int((value / 1023) * 255);
    analogWrite(pwmPin, value);
    delay(1);
  }
}
