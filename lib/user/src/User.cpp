//
// Created by Dev on 2019-01-17.
//

#include "../include/User.h"

///Constructor
User::User(networking::Connection connection)
        : username(""),
          password(""),
          currentConnection(connection),
          authenticated(false),
          role(User::Unknown)
{
    std::cout << "New user has been created" << std::endl;
};

///Destructor
User::~User(){
    //std::cout << "User has been destroyed" << std::endl;
}

///Getters
const std::string& User::getUsername() const {
    return this->username;
}

const std::string& User::getPassword() const {
    return this->password;
}

const networking::Connection& User::getConnection() {
    return this->currentConnection;
}

bool User::isAuthenticated(){
    return this->authenticated;
}

///Setters
void User::setUsername(const std::string &username) {
    this->username = username;
}

void User::setPassword(const std::string &password) {
    this->password = password;
}

void User::setAuthenticated(bool b) {
    this->authenticated = b;
}

///User Message Container Operations
//deposits a message in the User's message container
void User::sendMessage(std::string &message) {
    this->userMessageDeque.push_back(message);
}

//returns a concatenated string of all of User's messages
std::string User::getUserMessagesConcatenated() {

    std::ostringstream concatenatedMessage;

    for (auto& message: userMessageDeque){
        concatenatedMessage << message << "\n";
    }

    return concatenatedMessage.str();

}

//clears User's message container
void User::clearMessages() {
    this->userMessageDeque.clear();
}

//check if message container is empty
bool User::isMessageEmpty() {
    return this->userMessageDeque.empty();
}
