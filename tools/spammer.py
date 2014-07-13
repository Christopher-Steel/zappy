#!/usr/bin/python3.3
import socket
import sys
import time

def spam_that_fucker(ip, port, team):
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect((ip, port))
    sock.setblocking(1)
    sock.send((team + "\n").encode())
    while 1 == 1:
        try:
            time.sleep(0.0001)
            sock.send('voir\n'.encode())
            print(sock.recv(4096).decode())
            sock.send('prend nourriture\n'.encode())
            print(sock.recv(4096).decode())
            sock.send('avance\n'.encode())
            print(sock.recv(4096).decode())
        except OverflowError:
            print("dammit, i overflowed again")
        except IOError:
            print("disconnected")
            sys.exit(1)

def main(ac, av):
    if (ac == 4):
        spam_that_fucker(av[1], int(av[2]), av[3])
    else:
        print('USAGE: spammer.py ip port team')

main(len(sys.argv), sys.argv)
