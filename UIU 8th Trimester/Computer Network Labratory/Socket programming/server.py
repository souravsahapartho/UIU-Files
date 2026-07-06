from socket import *

host = "127.0.0.1"
port = 8000

s = socket(AF_INET, SOCK_STREAM)
s.bind((host, port))

s.listen(1)

print("Server Listening for connections")

client_socket, client_addr = s.accept()

print(client_socket, client_addr)


data = client_socket.recv(1024)
msg = data.decode()
print(msg)

msg = "Hello from Server"
data = msg.encode()
client_socket.send(data)

s.close()
