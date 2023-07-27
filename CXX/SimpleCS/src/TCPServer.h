#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAXPACKEGESIZE 4096

class TCPServer {

public:
    int sockfd, newsockfd, n, pid;
    struct sockaddr_in serverAddres;
    struct sockaddr_in clientAddres;
    pthread_t serverThread;
    char msg[MAXPACKEGESIZE];
    static std::string Message;

    void Setup(int port);
    std::string Receive();
    std::string GetMessage();
    void Send(std::string msg);
    void Detach();
    void Clean();

private:
    static void* Task(void* argv);
};

#endif TCP_SERVER_H