import select
import socket
import sys

def get_socket_name(s, local_or_remote):
    addr = s.getsockname() if local_or_remote else s.getpeername()
    return addr

def get_ip_address(s, local_or_remote):
    addr = get_socket_name(s, local_or_remote)
    return addr[0]

def get_port(s, local_or_remote):
    addr = get_socket_name(s, local_or_remote)
    return addr[1]

def send_to_all(sock, message, server_socket, client_count):
    for socket in CONNECTION_LIST:
        if socket != server_socket and socket != sock:
            try:
                socket.send(message)
            except:
                socket.close()
                CONNECTION_LIST.remove(socket)
                client_count -= 1

def main():
   
    PORT = 1234
    CONNECTION_LIST = []
    RECV_BUFFER = 256
    SERVER_SOCKET = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    SERVER_SOCKET.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    SERVER_SOCKET.bind(("0.0.0.0", PORT))
    SERVER_SOCKET.listen(10)

    CONNECTION_LIST.append(SERVER_SOCKET)
    print(f"Server listening on port {PORT}...")

    while True:
        READ_SOCKETS, _, _ = select.select(CONNECTION_LIST, [], [])
        for sock in READ_SOCKETS:
            if sock == SERVER_SOCKET:
                sockfd, addr = SERVER_SOCKET.accept()
                CONNECTION_LIST.append(sockfd)
                print(f"New connection from {addr}")
                client_count += 1
                message = f"Hi-you are client :[{sockfd}] ({addr[0]}:{addr[1]}) connected to server 0.0.0.0\nThere are {client_count} clients connected\n"
                sockfd.send(message.encode())
            else:
                try:
                    data = sock.recv(RECV_BUFFER)
                    if data:
                        data_str = data.decode().strip()
                        if data_str.upper() == "QUIT":
                            message = f"Request granted [{sock}] - {get_ip_address(sock, False)}. Disconnecting...\n"
                            sock.send(message.encode())
                            message = f"<{get_ip_address(sock, False)} - [{sock}]> disconnected\n"
                            send_to_all(sock, message.encode(), SERVER_SOCKET, client_count)
                            client_count -= 1
                            sock.close()
                            CONNECTION_LIST.remove(sock)
                        else:
                            message = f"<{get_ip_address(sock, False)} - [{sock}]> {data_str}"
                            send_to_all(sock, message.encode(), SERVER_SOCKET, client_count)
                except:
                    message = f"Client [{sock}] forcibly hung up\n"
                    send_to_all(sock, message.encode(), SERVER_SOCKET, client_count)
                    print(f"Client {sock} forcibly hung up")
                    sock.close()
                    CONNECTION_LIST.remove(sock)
                    client_count -= 1
    SERVER_SOCKET.close()

main()