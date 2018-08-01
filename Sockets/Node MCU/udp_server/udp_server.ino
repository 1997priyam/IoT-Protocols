
#include <ESP8266WiFi.h>
#include <WiFiUDP.h>

const char* ssid = "Priyam";
const char* pw = "priyam123456";
char data[200] ={};
int packetsize = 0; 
String receiveddata="";
//WiFiServer Server(80);
WiFiUDP Server;

void setup() {
  Serial.begin(9600);
  //setup AP
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, pw);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  // Start the server
  Server.begin(80);
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());
}
  


void loop() {
  
    char message = Server.parsePacket();
    packetsize = Server.available();
    if (message)
    {
      
     Server.read(data,packetsize);
     delay(100);
     IPAddress remoteip=Server.remoteIP();
     delay(100);
     Serial.println(Server.beginPacket(remoteip,81));
     Serial.println(remoteip);
     Serial.println(Server.remotePort());
     Serial.println(data);
     Server.write(data);
     Server.endPacket();
    }

    if(packetsize) {
      Serial.println(packetsize);
      for (int i=0;packetsize > i ;i++)
      {
        receiveddata+= (char)data[i];
      }
        
      Serial.print(receiveddata);
      Serial.println();
      receiveddata="";
    }
    delay(100);
  
  if(WiFi.status()==!WL_CONNECTED)
  {
    Serial.print(".");
    delay(100);
  }
}

