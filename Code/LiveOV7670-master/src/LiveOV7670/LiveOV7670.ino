<<<<<<< HEAD




#define trigPin 11
#define echoPin 10
#include <NewPing.h>

// change setup.h to switch between buffered and pixel-by-pixel processing
#include "setup.h"



void setup() {
  // This is not necessary and has no effect for ATMEGA based Arduinos.
  // WAVGAT Nano has slower clock rate by default. We want to reset it to maximum speed
  //CLKPR = 0x80; // enter clock rate change mode
  //CLKPR = 0; // set prescaler to 0. WAVGAT MCU has it 3 by default.
  Serial.begin (9600);
  pinMode(6, OUTPUT);
  


  initializeScreenAndCamera();
}
NewPing sonar(trigPin, echoPin, 200);
int counter = 0;
float distance = 10;
int end1 = 1;

void loop() {
  
  
  //Serial.println(counter);
  //Serial.println(int(distance));
  //delay(1000);
  if (!(counter < (2*distance))){
    delay(50);  // Wait 50ms between pings (about 20 pings/sec). 29ms    
    unsigned int uS = sonar.ping(); // Send ping, get ping time in 
    Serial.print("Ping: ");
    distance = sonar.convert_cm(uS);
    if (int(distance) != 0){
      end1 = 1;
      Serial.println("set new num");
    }
    Serial.print(distance); // Convert ping time to distance and print result (0 = outside set distance range, no ping echo)
    Serial.println("cm");
    counter = 0;
  }
  if (distance < 30){
    Serial.println("turn on");
    if (counter  < distance){
      digitalWrite(6, HIGH);
    }else{
      Serial.print("turn off");
        digitalWrite(6, LOW);
    }
  }
  Serial.println(end1);
  processFrame(int(distance), end1);
  end1 = 0;
  counter++;
}
=======




#define trigPin 8
#define echoPin 7
#include <NewPing.h>

// change setup.h to switch between buffered and pixel-by-pixel processing
#include "setup.h"



void setup() {
  // This is not necessary and has no effect for ATMEGA based Arduinos.
  // WAVGAT Nano has slower clock rate by default. We want to reset it to maximum speed
  //CLKPR = 0x80; // enter clock rate change mode
  //CLKPR = 0; // set prescaler to 0. WAVGAT MCU has it 3 by default.
  Serial.begin (9600);
  pinMode(6, OUTPUT);
  


  initializeScreenAndCamera();
}
NewPing sonar(trigPin, echoPin, 200);
int counter = 0;
float distance = 0;

void loop() {
  processFrame();
  Serial.println(counter);
  Serial.println(distance*2);
  if (!(counter < (2*distance))){
    delay(50);  // Wait 50ms between pings (about 20 pings/sec). 29ms    
    unsigned int uS = sonar.ping(); // Send ping, get ping time in 
    Serial.print("Ping: ");
    distance = sonar.convert_cm(uS);
    Serial.print(distance); // Convert ping time to distance and print result (0 = outside set distance range, no ping echo)
    Serial.println("cm");
    counter = 0;
  }
  if (distance < 30){
    Serial.println("turn on");
    if (counter  < distance){
      digitalWrite(6, HIGH);
    }else if (10  < distance){
      if (counter > distance){
        Serial.print("turn off");
        digitalWrite(6, LOW);
      }
    }else{
      digitalWrite(6, HIGH);
    }
  }
  
  counter++;
}
>>>>>>> 49a95cb9f550fe4027a04263b9cfc2870c533d4b
