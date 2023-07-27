#include <iostream>
#include <signal.h>
#include "TCPClient.h"

TCPClient tcpc;

void sig_exit(int s) {
    tcpc.Exit();
    exit(0);
}

int main(int argc, char *argv[]) {
    //Установка обработчика выхода из программы
    signal(SIGINT, sig_exit);

    tcpc.Setup("127.0.0.1", 11999);

    //инициализация генератора случайных чисел
    srand(time(NULL));

    while (true){
        //отправляем строку на сервер
        tcpc.Send(std::to_string(rand() % 25000));
        //получаем ответ сервера
        std::string rec = tcpc.Recive();
        
        if(rec != ""){
            //выводим ответ сервера
            std::cout << "Server response: " << rec << std::endl;
        }

        //засыпаем на секунду
        sleep(1);
    }
    return 0;
}