import socket
c = socket.socket()

x = int(input("enter sever IP :"))

c.connect(('localhost', x))

print("connected")

y = input("enter file name (ex : file.txt ) :")

c.send(bytes(y, 'utf-8'))

file = open(y, "wb")

file.write(c.recv(1024))
