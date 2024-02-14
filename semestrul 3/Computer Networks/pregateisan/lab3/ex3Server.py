import socket
import threading

mylock = threading.Lock()
clients = set()

def worker(server):
    global mylock, clients
    try:
        data, address = server.recvfrom(1024)
        print("New client:", address)
        mylock.acquire()
        clients.add(address)
        mylock.release()
    except socket.error as msg:
        print('error', msg.strerror)

def send_clients_info(client_socket, client_address):
    global clients
    mylock.acquire()
    client_list = ",".join([f"{ip[0]}:{ip[1]}" for ip in clients])
    mylock.release()
    client_socket.sendto(client_list.encode('utf-8'), client_address)

def main():
    try:
        server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        server.bind(('0.0.0.0', 1234))
        print("Server listening...")
    except socket.error as msg:
        print(msg.strerror)
        exit(-1)

    while True:
        data, client_address = server.recvfrom(1024)
        t = threading.Thread(target=send_clients_info, args=(server, client_address))
        t.start()

if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("Server shutting down...")
        exit(0)
