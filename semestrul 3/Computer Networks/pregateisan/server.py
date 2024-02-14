import sys
import struct
import threading
import socket

mylock = threading.Lock()
e = threading.Event()
e.clear()
threads = []


def worker(client_socket):
    global mylock, e
    try:
       # mylock.acquire()
        string_data='10+2;'
        string_data_encoded = string_data.encode('utf-8')
        client_socket.send(string_data_encoded)
       # wait(2)
        string_data="4/2;"
        string_data_encoded = string_data.encode('utf-8')
        client_socket.send(string_data_encoded)
        #wait(2)
        string_data="3+1;"
        string_data_encoded = string_data.encode('utf-8')
        client_socket.send(string_data_encoded)
        #wait(2)
       # mylock.release()
        #mylock.acquire()
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
        client_socket.send(nr_data)
        #mylock.release()
  
    except socket.error as msg:
        print('error:', msg.strerror)


def resetSrv():
    global mylock, threads, e
    while True:
        e.wait()
        for t in threads:
            t.join()
        print("all threads are finished")
        e.clear()
        mylock.acquire()
        threads = []
        mylock.release()

def main():
    try:
        rs = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        rs.bind(('0.0.0.0', 1234))
        rs.listen(5)
    except socket.error as msg:
        print(msg.strerror)
        exit(-1)
    t = threading.Thread(target=resetSrv, daemon=True)
    t.start()
    while True:
        cs, addrc = rs.accept()
        t = threading.Thread(target=worker, args=(cs,))  
        threads.append(t)
        t.start()

main()

 