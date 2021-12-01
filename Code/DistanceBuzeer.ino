#define trigPin 8
#define echoPin 7
#include <NewPing.h>

void setup() {
  Serial.begin (9600);
  pinMode(6, OUTPUT);
}

NewPing sonar(trigPin, echoPin, 200);
void loop() {
  delay(50);  // Wait 50ms between pings (about 20 pings/sec). 29ms    
  unsigned int uS = sonar.ping(); // Send ping, get ping time in 
  Serial.print("Ping: ");
  float distance = sonar.convert_cm(uS);
  Serial.print(distance); // Convert ping time to distance and print result (0 = outside set distance range, no ping echo)
  Serial.println("cm");
  delay(distance * 100);
  digitalWrite(6, HIGH);
  delay(distance * 100);
  digitalWrite(6, LOW);
  
  
} 
