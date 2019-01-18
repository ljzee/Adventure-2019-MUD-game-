//
// Created by Andrew on 2019-01-17.
//

/////////////////////////////////////////////////////////////////////////////
// Auth.cpp
//
// This library will hold our implementation for auth
//
//
/////////////////////////////////////////////////////////////////////////////
#include "../include/Auth.h"
#include "ChatWindow.h"
#include "Client.h"

using networking::Server
using networking::Connection
using networking::Message


namespace user {

    class Auth {

    public:
        promptLogin(ChatWindow Window);
        authSession(Connection c);
        createUser(Connection c);
    };


}

std::string
promptLogin(ChatWindow Window);
    std::string loginMessage{""};
    chatWindow.DisplayText{"Enter a username (type NEW to create account):"};
    std::string userName = Window->impl.onTextEntry.text;
    chatWindow.DisplayText{"Enter the password for this username (or for new account):"};
    std::string pwd = Window->impl.onTextEntry.text;
    //hash pwd before send;
    if (username == NEW){
        std::string loginMessage = "!NEW " + userName + " " + pwd;
        return loginMessage;
    }
    else {
        std::string loginMessage = "!LOGIN " + userName + " " + pwd;
        return loginMessage;
    }


void authSession(Connection c){



};

void createUser(Connection c){


};