#include <Arduino.h>
#include <WiFi.h>

#define RXp2 23
#define TXp2 22

#define ssid     "urSSID"               //change this to get in loop
#define password "urPASS"

void setup() {
  // Wi-Fi connection
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2);
  // pinMode(34, OUTPUT);                     //pin 34,35 only input mode 
  // pinMode(35, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(21, OUTPUT);
}

void loop() {
  if (touchRead(27) >= 40){
    digitalWrite(26, HIGH);
  } else digitalWrite(26, LOW);

  if (touchRead(33) >= 40){
    digitalWrite(25, HIGH);
  } else digitalWrite(25, LOW);

  // if (touchRead(32) >= 40){
  //   digitalWrite(35, HIGH);
  // } else digitalWrite(35, LOW);

  // if (touchRead(2) >= 40){
  //   digitalWrite(34, HIGH);
  // } else digitalWrite(34, LOW);

  if (touchRead(4) >= 40){
    digitalWrite(5, HIGH);
  } else digitalWrite(5, LOW);

  Serial2.printf("%d, %d, %d, %d, %d \r\n", touchRead(27), touchRead(33), touchRead(32), touchRead(2), touchRead(4));
  // digitalWrite(34, HIGH);
  // delay(50);
  // digitalWrite(35, HIGH);
  // delay(500);
  // digitalWrite(25, HIGH);
  // delay(500);
  digitalWrite(21, HIGH);
  delay(50);
  // digitalWrite(21, HIGH);
  // delay(500);
  // Serial2.write("23131\r\n");

  
  // delay(500);
  // digitalWrite(34, LOW);
  // delay(500);
  // digitalWrite(35, LOW);
  // delay(500);
  // digitalWrite(25, LOW);
  // delay(500);
  // digitalWrite(26, LOW);
  // delay(500);
  digitalWrite(21, LOW);
  delay(50);
  // Serial.println(Serial2.read());
}
