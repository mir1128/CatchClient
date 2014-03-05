#include "SocketThread.h"
#include <iostream>

int main(){
    SocketThread socketThread;

    std::string input;
    while (true){
        std::cin >>   input ;
        socketThread.sendMessage(input);

    }
    return 0;
}


