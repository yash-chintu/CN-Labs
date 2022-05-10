import socket

s = socket.socket()
print('Socket created')

employee_details = {
    1: {"total_leaves": 10,
        "current_balance": 4,
        "extra_leaves": 0},
    2: {"total_leaves": 9,
        "current_balance": 4,
        "extra_leaves": 0},
    3: {"total_leaves": 8,
        "current_balance": 4,
        "extra_leaves": 0},
    4: {"total_leaves": 7,
        "current_balance": 4,
        "extra_leaves": 0},
    5: {"total_leaves": 6,
        "current_balance": 4,
        "extra_leaves": 0},
    6: {"total_leaves": 5,
        "current_balance": 4,
        "extra_leaves": 0},
}

s.bind(('localhost', 9999))

s.listen(1)

c, addr = s.accept()
print("Connected with ", addr)

eid = int(c.recv(1024).decode())

if employee_details[eid]["current_balance"] >= 1:
    employee_details[eid]["current_balance"] -= 1
else:
    employee_details[eid]["extra_leaves"] += 1

c.send(bytes(str(employee_details[eid]), 'utf-8'))
