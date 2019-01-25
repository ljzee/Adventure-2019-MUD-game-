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

using networking::Server
using networking::Connection
using networking::Message


namespace user {

    std::string
    Login::promptLogin(const ChatWindow& Window){
       std::string loginMessage{""};
        chatWindow.DisplayText{"Enter a username (type NEW to create account):"};
        std::string userName = Window->impl.onTextEntry.text;
        chatWindow.DisplayText{"Enter the password for this username (or for new account):"};
        std::string pwd = Window->impl.onTextEntry.text;
        //hash pwd before send;
        if (username == "NEW"){
            std::string loginMessage = "!NEW " + userName + " " + pwd;
            return loginMessage;
        }
        std::string loginMessage = "!LOGIN " + userName + " " + pwd;
        return loginMessage;
}


bool
Login::validateCred(const std::string pwd){






}
}


