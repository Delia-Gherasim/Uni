import multiprocessing
import threading
import time
import socket
import pickle
from collections import defaultdict


# DSM Library
class DSM:
    def __init__(self, process_id, all_processes):
        self.process_id = process_id
        self.all_processes = all_processes
        self.variables = {}
        self.subscribers = defaultdict(list)
        self.change_queue = []
        self.lock = threading.Lock()
        self.callbacks = {}

    def create_variable(self, name, value, subscribers):
        self.variables[name] = value
        self.subscribers[name] = subscribers
        if self.process_id in subscribers:
            self.callbacks[name] = lambda v: print(f"Callback: {name} changed to {v}")

    def write(self, name, value):
        if name not in self.variables:
            raise ValueError(f"Variable {name} does not exist.")
        if self.process_id not in self.subscribers[name]:
            raise PermissionError(f"Process {self.process_id} is not subscribed to {name}.")

        # Broadcast change to subscribers
        self._broadcast(name, value)

    def compare_and_exchange(self, name, expected_value, new_value):
        with self.lock:
            if self.variables[name] == expected_value:
                self.write(name, new_value)

    def _broadcast(self, name, value):
        for subscriber in self.subscribers[name]:
            self._send_message(subscriber, {"type": "NOTIFY", "name": name, "value": value})

    def _send_message(self, subscriber, message):
        # Simulated messaging (can use socket or multiprocessing queues)
        if subscriber != self.process_id:
            with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
                s.connect(self.all_processes[subscriber])
                s.sendall(pickle.dumps(message))

    def _listen(self):
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.bind(self.all_processes[self.process_id])
            s.listen()
            while True:
                conn, _ = s.accept()
                with conn:
                    data = conn.recv(1024)
                    if data:
                        message = pickle.loads(data)
                        self._handle_message(message)

    def _handle_message(self, message):
        if message["type"] == "NOTIFY":
            self._apply_change(message["name"], message["value"])

    def _apply_change(self, name, value):
        with self.lock:
            self.variables[name] = value
            self.change_queue.append((name, value))
            # Trigger callback
            if name in self.callbacks:
                self.callbacks[name](value)

    def start(self):
        threading.Thread(target=self._listen, daemon=True).start()


# Main Program
if __name__ == "__main__":
    # Define all process addresses
    all_processes = {
        0: ("127.0.0.1", 5000),
        1: ("127.0.0.1", 5001),
        2: ("127.0.0.1", 5002),
    }

    # Initialize DSM
    process_id = int(input("Enter process ID (0, 1, 2): "))
    dsm = DSM(process_id, all_processes)

    dsm.start()

    if process_id == 0:
        dsm.create_variable("x", 10, [0, 1])
        time.sleep(1)
        dsm.write("x", 20)
    elif process_id == 1:
        time.sleep(2)  # Allow time for variable creation
        print(f"Process {process_id} sees x = {dsm.variables['x']}")
