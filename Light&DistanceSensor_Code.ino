#include <Adafruit_NeoPixel.h>

#define PIN_NEO_PIXEL  8   // Arduino pin that connects to NeoPixel
#define VOLCANO_PIXELS     10  // The number of LEDs (pixels) on NeoPixel
#define CO2_PIXELS      21
#define DELAY_INTERVAL 300
float distance = 0;               //stores the distance measured by the distance sensor
const int trigPin = 11;           //connects to the trigger pin on the distance sensor
const int echoPin = 12;           //connects to the echo pin on the distance sensor


Adafruit_NeoPixel NeoPixel(21, PIN_NEO_PIXEL, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin (9600);
  NeoPixel.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pinMode(trigPin, OUTPUT);   //the trigger pin will output pulses of electricity
  pinMode(echoPin, INPUT);    //the echo pin will measure the duration of pulses coming back from the distance
  pinMode(8, OUTPUT);
}

void loop() {
  NeoPixel.clear();
  distance = getDistance();   //variable to store the distance measured by the sensor

  Serial.print(distance);     //print the distance that was measured
  Serial.println(" in");      //print units after the distance
  if (distance <= 10) {                       //if the object is close
  for (int pixel = 2; pixel < 9; pixel++) { 
      
    NeoPixel.setPixelColor(pixel, NeoPixel.Color(255, 0, 0)); // it only takes effect if pixels.show() is called
    delay(DELAY_INTERVAL);
    NeoPixel.show();
  }
  for (int co = 9; co < 21; co++) {
    if (co < 20){
       NeoPixel.setPixelColor(co, NeoPixel.Color(255,255,255)); 
       delay(450);
       NeoPixel.show();
    }
    else if (co > 19){
      NeoPixel.setPixelColor(co, NeoPixel.Color(255,0,0)); 
       delay(450);
       NeoPixel.show();
    }}
  }
  else{
    NeoPixel.clear();
  }
  }
  
  
  float getDistance()
{
  float echoTime;                   //variable to store the time it takes for a ping to bounce off an object
  float calculatedDistance;         //variable to store the distance calculated from the echo time

  //send out an ultrasonic pulse that's 10ms long
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  echoTime = pulseIn(echoPin, HIGH);      //use the pulsein command to see how long it takes for the
                                          //pulse to bounce back to the sensor

  calculatedDistance = echoTime / 148.0;  //calculate the distance of the object that reflected the pulse (half the bounce time multiplied by the speed of sound)

  return calculatedDistance;              //send back the distance that was calculated

}

  
