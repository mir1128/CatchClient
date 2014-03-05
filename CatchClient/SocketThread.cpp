//
// Created by jieliu on 3/5/14.
// Copyright (c) 2014 ___FULLUSERNAME___. All rights reserved.
//

#include "SocketThread.h"

#include <unistd.h>
#include <pthread.h>
#include <iostream>

SocketThread::SocketThread()
{
    std::string address = "127.0.0.1";
    pClientSocket = new ClientSocket(4321, address);

    pthread_t id;
    int ret = pthread_create(&id, NULL, thread, (void*)pClientSocket);
    if (ret) {
        std::cout << "Create Socket Thread!" << std::endl;
    }
}

void* SocketThread::thread(void *ptr)
{
    ClientSocket* pSocket = (ClientSocket*)ptr;
    std::string receiveMessage= pSocket->receiveMessage();
    while (receiveMessage != "Great!!!!! You made it!"){
        std::cout << receiveMessage << std::endl;
        receiveMessage= pSocket->receiveMessage();
    }
    std::cout << receiveMessage << std::endl;
    return NULL;
}