//
// Created by jieliu on 3/5/14.
// Copyright (c) 2014 ___FULLUSERNAME___. All rights reserved.
//


#ifndef __SocketThread_H_
#define __SocketThread_H_

#include "ClientSocket.h"

class SocketThread {
private:
    ClientSocket* pClientSocket;

public:
    SocketThread();

    virtual ~SocketThread() {
        delete pClientSocket;
    }

    void sendMessage(std::string message){
        pClientSocket->sendMessage(message);
    }

    static void* thread(void *ptr);
};


#endif //__SocketThread_H_
