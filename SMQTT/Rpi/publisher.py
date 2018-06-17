import paho.mqtt.client as mqtt
import ssl
 
MQTT_SERVER = "etilabs.tk"
MQTT_PATH = "/priyam"
# The callback for when the client receives a CONNACK response from the server.
def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))
    
def on_publish(mqttc, obj, mid):
    print("mid: " + str(mid))
    pass
    
        
user = "priyam"
password = "priyam"
client = mqtt.Client("Rpi priyam")
client.username_pw_set(user, password=password)
client.on_connect = on_connect
client.on_publish = on_publish
client.tls_set(ca_certs=None, certfile=None, keyfile=None, cert_reqs=ssl.CERT_REQUIRED,
    tls_version=ssl.PROTOCOL_SSLv23, ciphers=None)
client.connect(MQTT_SERVER, 8883, 60)
 
infot = client.publish(MQTT_PATH, "Hello i am priyam")
infot.wait_for_publish()



# Blocking call that processes network traffic, dispatches callbacks and
# handles reconnecting.
# Other loop*() functions are available that give a threaded interface and a
# manual interface.

