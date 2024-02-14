#include <sys/types.h>
#include <stdint.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char s1[100];
    int udp_sock, tcp_sock, n, length;
    struct sockaddr_in udp_server, tcp_server, from;
    struct hostent *hp;

    if (argc != 3) {
        printf("Usage: %s <server_name> <udp_port>\n", argv[0]);
        exit(1);
    }

    udp_sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (udp_sock < 0) {
        perror("UDP socket error");
        exit(1);
    }

    udp_server.sin_family = AF_INET;

    hp = gethostbyname(argv[1]);
    if (hp == 0) {
        printf("Unknown host\n");
        exit(1);
    }

    bcopy((char *)hp->h_addr, (char *)&udp_server.sin_addr, hp->h_length);
    udp_server.sin_port = htons(atoi(argv[2]));
    length = sizeof(struct sockaddr_in);

    for (int i = 0; i < 3; ++i) {
        n = recvfrom(udp_sock, &s1, sizeof(s1), 0, (struct sockaddr *)&from, &length);
        if (n < 0) {
            perror("recv");
            exit(1);
        }
        printf("String is: %s\n", s1);
    }

    close(udp_sock);

    tcp_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (tcp_sock < 0) {
        perror("TCP socket error");
        exit(1);
    }

    memset(&tcp_server, 0, sizeof(struct sockaddr_in));
    tcp_server.sin_family = AF_INET;
    tcp_server.sin_port = htons(1234);
    tcp_server.sin_addr.s_addr = inet_addr("192.168.58.1");

    if (connect(tcp_sock, (struct sockaddr *)&tcp_server, sizeof(struct sockaddr_in)) < 0) {
        perror("Error connecting");
        exit(1);
    }

    uint16_t r1 = 0, r2 = 12, r3 = 1, r4 = 2, r5 = 2, r6 = 4;

    r1 = htons(r1);
    send(tcp_sock, &r1, sizeof(r1), 0);

    r2 = htons(r2);
    send(tcp_sock, &r2, sizeof(r2), 0);
    r3 = htons(r3);
    send(tcp_sock, &r3, sizeof(r3), 0);

    r4 = htons(r4);
    send(tcp_sock, &r4, sizeof(r4), 0);

    r5 = htons(r5);
    send(tcp_sock, &r5, sizeof(r5), 0);

    r6 = htons(r6);
    send(tcp_sock, &r6, sizeof(r6), 0);

    uint16_t nr;
    recv(tcp_sock, &nr, sizeof(nr), 0);
    nr = ntohs(nr);
    printf("Received grade: %hu\n", nr);

    close(tcp_sock);

    return 0;
}