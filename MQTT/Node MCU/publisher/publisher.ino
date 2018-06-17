#include <ESP8266WiFi.h>
#include <MQTT.h>
 
 
const char* ssid     = "Priyam";
const char* password = "priyam123456";
 
WiFiClient WiFiclient;
MQTTClient client;


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
 connect();
}
 
void connect() {
 while (!client.connect("nodemcu 1", "priyam", "priyam")) {
   Serial.print(".");
 }
 
 Serial.println("\nconnected!");
 
}
 
void loop() {


 
 client.loop();
 if(!client.connected())
 {
   connect();
 }
 

   client.publish("/priyam", "Hello !!");
   Serial.println("Pubishing Hello !! on topic /priyam");
   delay(2000);
  
 }

