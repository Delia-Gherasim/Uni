import socket
import struct

try:
    s = socket.create_connection(("172.31.69.6", 1234))
except socket.error as msg:
    print("error: ", msg.strerror)
    exit(-1)

sir = input("sir: ")
index = int(input("starting index: "))
length = int(input("length of substring: "))

s.sendall(struct.pack('!H', length))
s.sendall(struct.pack('!H', index))
s.sendall(sir.encode('utf-8'))

response = s.recv(1024).decode('utf-8')
print("received response from server:", response)
s.close()
