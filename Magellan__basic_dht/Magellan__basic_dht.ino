#include "Magellan.h"
Magellan magel;

#include <DHT.h>;
#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino


//Variables
int chk;

char auth[] = "208c5c10-46e7-11e9-96dd-9fb5d8a71344"; 		//  Token Key from www.aismagellan.io

String payload;

void setup() {
  Serial.begin(9600);
  magel.begin(auth);
  dht.begin();
}

void loop() {
  int temp = dht.readTemperature();
  int humid = dht.readHumidity();;

  payload = "{\"Temperature\":" + String(temp) + ",\"Humidity\":" + String(humid) + "}";
  Serial.println(payload);
  //  payload = "{\Hello"
  magel.post(payload);

  delay(10000);
}
