#!/usr/bin/python3.3
import resource
import socket
import sys

def infini_connect(ip, port):
    resource.setrlimit(resource.RLIMIT_NOFILE, (2048, 2048))
    socks = [];
    while 1 == 1:
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.connect((ip, port))
        socks.append(sock)
    for s in socks:
        s.close()

def main(ac, av):
    if (ac == 3):
        infini_connect(av[1], int(av[2]))
    else:
        print("USAGE: infini-connector.py ip port")

main(len(sys.argv), sys.argv)
