
#include <ESP8266WiFi.h>
#include <WiFiUDP.h>

WiFiUDP Client;

byte serdata=0;
byte fromserver=0;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println("Priyam");
  
  WiFi.begin("Priyam", "priyam123456");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  // Print the IP address
  Serial.println(WiFi.localIP());
    Client.begin(81);
}

void loop() 
{
const int port=80;
int i=0;  
   /*Serial.print("connecting to ");
    Serial.println(ip);*/
udpsend();
  
  char serverack = Client.parsePacket();
  Serial.println(serverack);
  if (serverack)
    {
    fromserver=Client.read();
    Serial.println(fromserver);
    delay(1000);
      if (fromserver==serdata)
        {
          serdata=serdata+1;
        }
      else
         {
         Serial.println("not equal");
         Serial.println(fromserver);
          udpsend();
         }
    }
   else
   {
    Serial.println("no data");
    delay(1000);
    }
    
    //client.stop();
    delay(1000);
}

void udpsend()
  {
    const char ip[]="192.168.137.1";
  Client.beginPacket(ip,80);
  Client.write(serdata);
  Client.endPacket();
  delay(1000);
  return;
  }

