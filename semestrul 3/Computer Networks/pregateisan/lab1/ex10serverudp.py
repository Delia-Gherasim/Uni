#The client sends to the server two strings. 
# The server sends back the character with the largest number of occurrences on the same positions in both strings together with its count.
import socket
import sys
import struct

def max_occurrences(string1, string2):
    result_char = ''
    max_count = 0
    for c1, c2 in zip(string1, string2):
        if c1 == c2:
            count = string1.count(c1)
            if count > max_count:
                max_count = count
                result_char = c1
    return max_count, result_char


def main():
    server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server.bind(('0.0.0.0', 1234))
    print("server listening...")
    while True:
        string1, address = server.recvfrom(1024)
        string2, address=server.recvfrom(1024)
        string1=string1.decode('utf-8')
        string2 = string2.decode('utf-8')
        count, char = max_ocuurences(string1, string2)
        max_char = char.encode('utf-8')
        count_bytes = struct.pack('!H', count)
        server.sendto(max_char, address)
        server.sendto(count_bytes, address)
        

main()