#include <dht.h>
#include <ESP8266WiFi.h>
#include <MQTTClient.h>
 
 
const char* ssid     = "Agarwal's";
const char* password = "1501051136";
 
WiFiClient WiFiclient;
MQTTClient client;
dht DHT;

unsigned long lastMillis = 0;

 
void setup() {
  pinMode(2, OUTPUT);
  pinMode(0,OUTPUT);
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
 client.onMessage(messageReceived);
}
 
void connect() {
 while (!client.connect("nodemcu 1", "priyam", "priyam")) {
   Serial.print(".");
 }
 
 Serial.println("\nconnected!");
 client.subscribe("/priyam/light");
 client.subscribe("/priyam/light2");
}
 
void loop() {
 int chk = DHT.read11(13);
 double temp = DHT.temperature;
 double humidity = DHT.humidity;

 
 client.loop();
 if(!client.connected())
 {
   connect();
 }
 
if(millis() - lastMillis > 3000)
{
   lastMillis = millis();
   client.publish("/priyam/temp", (String)temp, false, 1);
  Serial.println(temp);
  delay(200);
   client.publish("/priyam/humidity", (String)humidity, false, 1);
   Serial.println(humidity);
 }
   
   
   
 
}

void messageReceived(String &topic, String &payload) {
  Serial.println("incoming: " + topic + " - " + payload);
  if(topic=="/priyam/light"&&payload=="0")
  digitalWrite(0,HIGH);
  else if(topic=="/priyam/light"&&payload=="1") 
  digitalWrite(0,LOW);
  else if(topic=="/priyam/light2"&&payload=="0") 
  digitalWrite(2,HIGH);
  else if(topic=="/priyam/light2"&&payload=="1") 
  digitalWrite(2,LOW);
  else
  Serial.println("Invalid payload");
}

