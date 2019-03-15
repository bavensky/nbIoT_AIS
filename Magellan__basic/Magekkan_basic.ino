#include "Magellan.h"
Magellan magel;

//Variables
int chk;

char auth[] = "208c5c10-46e7-11e9-96dd-9fb5d8a71344"; 		//  Token Key from www.aismagellan.io

String payload;

void setup() {
  Serial.begin(9600);
  magel.begin(auth);
}

void loop() {
  int temp = 25;
  int humid = 50;

  payload = "{\"Temperature\":" + String(temp) + ",\"Humidity\":" + String(humid) + "}";
  Serial.println(payload);
  //  payload = "{\Hello"
  magel.post(payload);

  delay(10000);
}
