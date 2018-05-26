import paho.mqtt.client as mqtt
import time
time.sleep(20)
MQTT_SERVER = "broker.shiftr.io"
MQTT_PATH = "/priyam"
# The callback for when the client receives a CONNACK response from the server.
def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))
    
        
user = "try"
password = "try"
 
client = mqtt.Client("Rpi priyam")
client.username_pw_set(user, password=password)
client.on_connect = on_connect
client.connect(MQTT_SERVER, 1883, 60)

while True:
    time.sleep(3)
    client.publish(MQTT_PATH, "hello, Priyam")
    
client.loop_forever() 
# Blocking call that processes network traffic, dispatches callbacks and
# handles reconnecting.
# Other loop*() functions are available that give a threaded interface and a
# manual interface.

