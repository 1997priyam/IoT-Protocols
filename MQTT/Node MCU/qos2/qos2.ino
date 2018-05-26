#include <ESP8266WiFi.h>
#include <MQTTClient.h>
 
const char* ssid     = "Priyam"; 
const char* password = "priyam12345";
 
WiFiClient WiFiclient;
MQTTClient client;
 
unsigned long lastMillis = 0;

 
void setup() {
 Serial.begin(115200);
 delay(10);
 Serial.println();
 Serial.println();
 Serial.print("Connecting to ");
 Serial.println(ssid);
 
 WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
   delay(500);
   Serial.print(".");
 }
 
 Serial.println("");
 Serial.println("WiFi connected");  
 Serial.println("IP address: ");
 Serial.println(WiFi.localIP());
 
 delay(2000);
 
 Serial.print("connecting to MQTT broker...");
 client.begin("bitvolt.tk", WiFiclient);
 client.onMessage(messageReceived);

 connect();
}
 
void connect() {
 while (!client.connect("nodemcu", "priyam", "priyam")) {
   Serial.print(".");
 }
 
 Serial.println("\nconnected!");
 client.subscribe("test",2);
}
 
void loop() {

 client.loop();
 if(!client.connected()) {
   connect();
   
 }
}
 
void messageReceived(String &topic, String &payload) {
  Serial.println("incoming: " + topic + " - " + payload);
  
}
  
  

