#include "TCPServer.h"

std::string TCPServer::Message;

//Основной метод сервера, обработка клиента
void* TCPServer::Task(void* arg) {
    int n;
    int newsockfd = (long) arg;
    char msg[MAXPACKEGESIZE];
    pthread_detach(pthread_self());

    while(true) {
        n = recv(newsockfd, msg, MAXPACKEGESIZE, 0);
        if (n == 0) {
            close(newsockfd);
            break;
        }
        msg[n] = 0;
        Message = std::string(msg);
    }
    return 0;
}

//Установка сервера
void TCPServer::Setup(int port) {
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serverAddres, 0, sizeof(serverAddres));
    serverAddres.sin_family = AF_INET;
    serverAddres.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddres.sin_port = htons(port);
    bind(sockfd, (struct sockaddr *)&serverAddres, sizeof(serverAddres));
    listen(sockfd, 5);
}

//Получение информации от клиента
std::string TCPServer::Receive() {
    std::string str;
    while (true) {
        socklen_t sosize = sizeof(clientAddres);
        newsockfd = accept(sockfd, (struct sockaddr *)&clientAddres, &sosize);
        str = inet_ntoa(clientAddres.sin_addr);
        pthread_create(&serverThread, NULL, &Task, (void*)newsockfd);
    }
    return str;
}

//Возвращаем сообщение клиента
std::string TCPServer::GetMessage() {
    return Message;
}

//Отправка сообщения клиенту
void TCPServer::Send(std::string msg) {
    send(newsockfd, msg.c_str(), msg.length(), 0);
}

//Очистка сообщения
void TCPServer::Clean() {
    Message = "";
    memset(msg, 0, MAXPACKEGESIZE);
}

//Закрываем сокеты клиента и сервера
void TCPServer::Detach() {
    close(sockfd);
    close(newsockfd);
}