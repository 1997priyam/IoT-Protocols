
import socket # for socket
import sys 
 
try:
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print "Socket successfully created"
except socket.error as err:
    print "socket creation failed with error %s" %(err)
 
# default port for socket
port = 12345
 
try:
    #host_ip = socket.gethostbyname('localhost')
    host_ip = "192.168.137.5"
except socket.gaierror:
 
    # this means could not resolve the host
    print "there was an error resolving the host"
    sys.exit()
 
# connecting to the server
s.connect((host_ip, port))
s.send('Hey I am Priyam\r')
print s.recv(1024) 
print "the socket has successfully connected \
on port == %s" %(host_ip)
s.close()
