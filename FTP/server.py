import socket

s = socket.socket()

s.bind(('localhost', 9999))
s.listen(1)


c, addr = s.accept()

print("connected with ", addr)

y = c.recv(1024).decode()

print(y)

file = open(y, "rb")

file_data = file.read(1024)

c.send(file_data)
