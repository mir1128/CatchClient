//
// Created by jieliu on 3/5/14.
// Copyright (c) 2014 ___FULLUSERNAME___. All rights reserved.
//

#include "ClientSocket.h"

#include <stdio.h>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

ClientSocket::ClientSocket(short port, std::string& address) {
    if (!init(port, address)){
        std::cout << "init failed!" << std::endl;
    }
}

bool  ClientSocket::init(short port, std::string &address) {
    struct sockaddr_in server_addr;
    server_addr.sin_len = sizeof(struct sockaddr_in);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(address.c_str());
    bzero(&(server_addr.sin_zero), 8);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket error");
        return false;
    }

    if (!connect(server_socket, (struct sockaddr *) &server_addr, sizeof(struct sockaddr_in)) == 0) {
        perror("not connected.");
        return false;
    }
    return true;
}

void ClientSocket::sendMessage(std::string message)
{
    if (send(server_socket, message.c_str(), message.size(), 0) == -1) {
        perror("send error");
    }
}

std::string ClientSocket::receiveMessage()
{
    std::string result = "";
    char receiveMessage[1024] = {0};
    while (true) {
        memset(receiveMessage, 0, 1024);
        long byte_num = recv(server_socket, receiveMessage, 1024, 0);
        result += receiveMessage;
        if (byte_num != 1024)
        {
            break;
        }
    }
    return result;
}



