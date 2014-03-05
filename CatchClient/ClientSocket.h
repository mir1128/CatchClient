//
// Created by jieliu on 3/5/14.
// Copyright (c) 2014 ___FULLUSERNAME___. All rights reserved.
//


#ifndef __ClientSocket_H_
#define __ClientSocket_H_

#include <string>

class ClientSocket
{
private:
    int server_socket;

public:
    ClientSocket(short port, std::string& address);

    bool  init(short port, std::string& address);

    void sendMessage(std::string message);

    std::string receiveMessage();

};


#endif //__ClientSocket_H_
