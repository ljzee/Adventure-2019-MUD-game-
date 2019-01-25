/////////////////////////////////////////////////////////////////////////////
// Login.cpp
//
// This library will provide the login experience on client start.
//
//
/////////////////////////////////////////////////////////////////////////////
#include "Login.h"
#include "ChatWindow.h"
#include "Client.h"

using networking::Server;
using networking::Connection;
using networking::Message;


namespace user {

    std::string
    Login::promptLogin(ChatWindow& window, std::function<void(std::string)> onTextEntry){
        std::string loginMessage{""};

        window.displayText("Enter a username (type NEW to create account):");
        std::string userName = window.impl.onTextEntry.text;

        window.displayText("Enter the password for this username (or for new account):");
        std::string pwd = window.impl.onTextEntry.text;

        //hash pwd before send;
        if (userName == "NEW"){
            loginMessage = "!NEW " + userName + " " + pwd;
            return loginMessage;
        }
        loginMessage = "!LOGIN " + userName + " " + pwd;
        return loginMessage;
    }



    bool
    Login::validateCred(const std::string pwd){







    }



}