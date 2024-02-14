#A client sends to the server a string. The server returns the count of spaces in the string.
import socket
import struct
import threading
import sys

try:
    rs=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    rs.bind(('0.0.0.0', 1234))
    rs.listen(5)
except socket.error as msg:
    print(msg.strerror)
    exit(1)

cs, addrc=rs.accept()
try: 
    clientString=cs.recv(1024).decode('utf-8')
except socket.error as msg:
    print(msg.strerror)
    cs.close()
    

space_count=0
for char in clientString:
    if (char==" "):
        space_count=space_count+1
       
#resp=str(space_count).encode('utf-8')
response = struct.pack('!H', space_count)
cs.sendall(response)
cs.close()
