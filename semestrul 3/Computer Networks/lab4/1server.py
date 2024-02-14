import socket
import threading
import struct
import sys
import time



if __name__=='__main__':
    try:
        rs=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        rs.bind(('0.0.0.0',1234))
        rs.listen(5)
    except socket.error as msg:
        print(msg.strerror)
        exit(-1)
    command=client_socket.recv(1024).decode()
##am incercat