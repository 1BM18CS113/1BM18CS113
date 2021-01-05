# using UDP sockets, write a client-server program to make client sending the
# file name and the server to send back the contents of the requested file if
# present.

from socket import *

serverName = "127.0.0.1"
serverPort = 12000

clientSocket = socket(AF_INET, SOCK_DGRAM)
clientSocket.connect((serverName,serverPort))

sentence = input("Enter file name: \n")
clientSocket.sendto(bytes(sentence,"utf-8"),(serverName,serverPort))

filecontents,serverAddress = clientSocket.recvfrom(2048)
print ('From Server:', filecontents)

clientSocket.close()