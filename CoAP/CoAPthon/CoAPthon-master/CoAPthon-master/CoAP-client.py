from coapthon.client.helperclient import HelperClient

host = "192.168.137.139"
port = 5683
path ="basic"
print("0")
client = HelperClient(server=(host, port))
print("1")
response = client.get(path)
print("2")
print response.pretty_print()
client.stop()
