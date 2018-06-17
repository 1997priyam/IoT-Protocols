#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
 
const char* ssid = "Priyam";
const char* password = "priyam123456";
 
void setup () {
 
  Serial.begin(115200);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
 
    delay(1000);
    Serial.println("Connecting..");
 
  }
 
}
 
void loop() {
 
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
 
    HTTPClient http;  //Declare an object of class HTTPClient
 
    http.begin("http://192.168.137.233:80/");  //Specify request destination
    Serial.println("Connecting to the server....");
    int httpCode = http.GET();                                                                  //Send the request
 
    if (httpCode > 0) { //Check the returning code
 
      Serial.println("Successfully connected to the server..!!");
      String payload = http.getString();   //Get the request response payload
      Serial.println("Response received: "+payload);                     //Print the response payload
 
    }
 
    http.end();   //Close connection
    Serial.println("Connection Closed..!!");
  }
 
  delay(30000);    //Send a request every 30 seconds
 
}
