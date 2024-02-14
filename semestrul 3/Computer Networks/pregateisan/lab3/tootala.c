#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define UDP_PORT 1234

int main() {
    int udp_socket;
    struct sockaddr_in udp_server;

    udp_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (udp_socket == -1) {
        perror("UDP socket");
        exit(1);
    }

    udp_server.sin_family = AF_INET;
    udp_server.sin_port = htons(UDP_PORT);
    udp_server.sin_addr.s_addr = INADDR_ANY;

    if (bind(udp_socket, (struct sockaddr*)&udp_server, sizeof(udp_server)) == -1) {
        perror("UDP bind");
        close(udp_socket);
        exit(1);
    }

    char buffer[1024];
    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);

    printf("UDP Server listening on port %d...\n", UDP_PORT);

    while (1) {
        ssize_t recv_len = recvfrom(udp_socket, buffer, sizeof(buffer), 0, (struct sockaddr*)&client_addr, &addr_len);
        if (recv_len == -1) {
            perror("UDP recvfrom");
            continue;
        }

        buffer[recv_len] = '\0';
        printf("Received UDP registration: %s\n", buffer);

        // TODO: Extract client information and store it for future communication
    }

    close(udp_socket);
    return 0;
}
