from socket import *

server_host = "127.0.0.1"
server_port = 8080

server_socket = socket(AF_INET, SOCK_STREAM)






server_socket.connect((server_host, server_port))



msg = "Hello from Client"
data = msg.encode()
server_socket.send(data)




data = server_socket.recv(1024)
msg = data.decode()
print(msg)

server_socket.close()
