import socket
import struct
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#c = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(("192.168.182.135", 1234))
s.listen(J)
suma=0
while (True):
    c.adress=s.accept()
    d=c.recv(2)
    d=struct.unpack('!H', d)[0]

    suma=suma+d

c.send(struct.pack('!H', suma))
