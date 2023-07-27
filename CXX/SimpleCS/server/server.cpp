#include <iostream>
#include "TCPServer.h"

TCPServer tcps;

void* loop(void *m) {
    pthread_detach(pthread_self());

    while (true) {
        srand(time(NULL));
        char ch = 'a' + rand() % 26;
        std::string s(1, ch);
        std::string str = tcps.GetMessage();
        if (str != "") {
            std::cout << "Message: " << str << std::endl;
            tcps.Send("[client message: " + str + "] " + s);
            tcps.Clean();
        }
        usleep(1000);
    }
    tcps.Detach();
}

int main() {
    pthread_t msg;

    tcps.Setup(11999);

    if (pthread_create(&msg, NULL, loop, (void *)0) == 0) {
        tcps.Receive();
    }
    
    return 0;
}