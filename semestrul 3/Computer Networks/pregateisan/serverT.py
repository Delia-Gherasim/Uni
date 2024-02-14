import sys
import struct
import threading
import socket

try:
    rs = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    rs.bind(('0.0.0.0', 1234))
    rs.listen(5)
except socket.error as msg:
    print(msg.strerror)
    exit(-1)

client_socket, addrc = rs.accept()
try:
    string_data='10+2;'
    string_data_encoded = string_data.encode('utf-8')
    client_socket.send(string_data_encoded)
    wait(2)
    string_data="4/2;"
    string_data_encoded = string_data.encode('utf-8')
    client_socket.send(string_data_encoded)
    wait(2)
    string_data="3+1;"
    string_data_encoded = string_data.encode('utf-8')
    client_socket.send(string_data_encoded)
    wait(2)

    N=0
    while(N<6):
        data = client_socket.recv(4)
        nr = struct.unpack('!H', data)[0]
        if (N%2==0):
            print(client_socket,"answered ex  ",nr)
        else:
            print("with value ", nr)
        N=N-1
    nr=10
    nr_data = struct.pack('!H', nr)
    client_socket.sendall(nr_data)
    client_socket.close()

  
except socket.error as msg:
    print('error:', msg.strerror)
    client_socket.close()