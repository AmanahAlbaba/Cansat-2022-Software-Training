#include <Servo.h>
int const redPin = 9;
int const greenPin = 10;
int const bluePin = 11;
int const sensorPin = A0;
int angle;
Servo servo;
void setup() {
  servo.attach(3);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
   int sensorVal = analogRead(sensorPin);
   float voltage = (sensorVal/1024.0)*5.0;
   float temp = (voltage - 0.5)*100;
   angle = map(temp, -40, 125, 0, 179);
   servo.write(temp);
   Serial.println(temp);

   if (temp >= -40 && temp <= -10){
     Serial.println("blue");
     //blue
     analogWrite(redPin, 0);
     analogWrite(greenPin, 0);
     analogWrite(bluePin, 255);
   }

   else if (temp > -10 && temp <= 20){
     Serial.println("greee");
     //green
     analogWrite(redPin, 0);
     analogWrite(greenPin, 255);
     analogWrite(bluePin, 0);
   }
   else if (temp > 20 && temp <= 50){
     //yellow
     Serial.println("yellow");
     analogWrite(redPin, 0);
     analogWrite(greenPin, 255);
     analogWrite(bluePin, 255);
   }

   else if (temp > 50 && temp <= 80){
     //purple
     Serial.println("purple");
     analogWrite(redPin, 255);
     analogWrite(greenPin, 0);
     analogWrite(bluePin, 255);
   }

   else if (temp > 80 && temp <= 110){
     //red
     Serial.println("red");
     analogWrite(redPin, 255);
     analogWrite(greenPin, 0);
     analogWrite(bluePin, 0);
   }

   else if (temp > 110 && temp <= 125){
     //white
     Serial.println("white");
     analogWrite(redPin, 255);
     analogWrite(greenPin, 255);
     analogWrite(bluePin, 255);
   }
}
