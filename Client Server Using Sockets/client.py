import socket

c = socket.socket()

c.connect(('localhost', 9999))

eid = input("enter employee id: ")

c.send(bytes(eid,'utf-8'))

print(c.recv(1024).decode())

c.close()
