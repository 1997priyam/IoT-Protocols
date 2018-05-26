import RPi.GPIO as GPIO
from coapthon.server.coap import CoAP
from exampleresources import BasicResource
#from coapthon.resources.resource import Resource

#resource class
class RPiResource(BasicResource):
        channel = 12
        GPIO.setmode(GPIO.BOARD)
        GPIO.setup(channel, GPIO.IN)
        def render_GET(self, request):
                self.payload = "state=" + str(GPIO.input(self.channel))
                return self

#server class
class CoAPServer(CoAP):
        def __init__(self, host, port):
                CoAP.__init__(self, (host, port))
                self.add_resource('basic/',RPiResource())

if __name__ == "__main__":
        ip = "192.168.137.139"
        port = 5683
        server = CoAPServer(ip, port)
        server.listen()
