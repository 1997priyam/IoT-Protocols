#include <dht.h>
#include <ESP8266WiFi.h>
#include <MQTTClient.h>
 
 
const char* ssid     = "Priyam";
const char* password = "priyam12345";
 
WiFiClient WiFiclient;
MQTTClient client;
dht DHT;

 

 
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
 //client.subscribe("/example");
}
 
void loop() {
 int chk = DHT.read11(16);
 double temp = DHT.temperature;
 double humidity = DHT.humidity;

 
 client.loop();
 if(!client.connected())
 {
   connect();
 }
 

   client.publish("/priyam/temp", (String)temp);
   delay(3000);
   client.publish("/priyam/humidity", (String)humidity);
   delay(3000);
   
 
}

