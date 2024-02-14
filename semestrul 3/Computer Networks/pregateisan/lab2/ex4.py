import sys
import struct
import threading
import socket
import json

mylock = threading.Lock()
e = threading.Event()
e.clear()
threads = []
vectors = []


def send_vector(client_socket, vector):
    json_data = json.dumps(vector)
    client_socket.sendall(json_data.encode('utf-8'))


def merge_sort(arr):
    if len(arr) <= 1:
        return arr

    mid = len(arr) // 2
    left = arr[:mid]
    right = arr[mid:]

    left = merge_sort(left)
    right = merge_sort(right)

    return merge(left, right)


def merge(left, right):
    result = []
    i = j = 0

    while i < len(left) and j < len(right):
        if left[i][-1] <= right[j][0]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1

    result.extend(left[i:])
    result.extend(right[j:])

    return result


def worker(cs):
    global mylock, e

    try:
        cnumber_data = cs.recv(4)
        cnumber = struct.unpack('!I', cnumber_data)[0]
        if cnumber == 0:
            mylock.acquire()
            result = merge_sort(vectors.copy())
            mylock.release()
            result_len = len(result)
            cs.sendall(struct.pack('!I', result_len))
            send_vector(cs, result)
            return

        vector_data = cs.recv(4 * cnumber)
        vector = struct.unpack(f'!{cnumber}f', vector_data)  # Change to float
        mylock.acquire()
        vectors.append(vector)
        mylock.release()

    except socket.error as msg:
        print('error: ', msg.strerror)


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
        t = threading.Thread(target=worker, args=(cs,))  # Pass cs as a tuple
        threads.append(t)
        t.start()


main()
