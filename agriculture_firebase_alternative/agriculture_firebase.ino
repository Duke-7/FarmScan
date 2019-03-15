
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "https://farmscan123.firebaseio.com/"
#define WIFI_SSID "wifi"
#define WIFI_PASSWORD "1234567890"
float sensorValue;


void setup() {
WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
(WiFi.status() != WL_CONNECTED){
  delay(500);
  Serial.print(".");
}
Serial.println("WiFi Connected");
Serial.begin(9600);
Firebase.begin(FIREBASE_HOST);
}

}

void loop() {
  sensorValue= analogRead(A0);
  sensorValue = map(sensorValue,1023,0,0,100);
  Firebase.setFloat ("Moisture",sensorValue);
  delay(200);

}
