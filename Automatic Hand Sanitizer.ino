#include <Servo.h>
Servo servo1, servo2;
int angle = 10;
// defines pins numbers
const int trigPin = 12;
const int echoPin = 11;
// defines variables
long duration;
int distance;

void setup() {
  servo1.attach(8);
  servo1.write(angle);
  
  servo2.attach(9);
  servo2.write(angle);
  
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
}

void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
delay(10);

if(distance<10)
{
  servo1.write(0);
  servo2.write(0);
  delay(1000);
  }
  else
  {
    servo1.write(180);
    servo2.write(180);
    }
}
