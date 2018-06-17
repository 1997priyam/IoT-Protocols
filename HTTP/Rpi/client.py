import http.client

connection = http.client.HTTPConnection("localhost:8000")
connection.request("GET", "/")
response = connection.getresponse()
print("Status: {}, reason: {} and Response : {}".format(response.status, response.reason, response.read()))

connection.close()
