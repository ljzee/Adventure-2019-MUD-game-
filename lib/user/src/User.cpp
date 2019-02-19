//
// Created by Dev on 2019-01-17.
//

#include "../include/User.h"

///Constructor
User::User(networking::Connection connection)
        : username(),
          currentConnection(connection),
          authenticated(false),
          activeAvatarId(-1)
{
    std::cout << "New user has been created" << std::endl;
};

///Constructor for JSON Parsing
User::User(std::string username) {
    this->username = username;
}

///Destructor
User::~User(){
    //std::cout << "User has been destroyed" << std::endl;
}

///Getters
const std::string& User::getUsername() const {
    return this->username;
}


const networking::Connection& User::getConnection() const{
    return this->currentConnection;
}

bool User::isAuthenticated(){
    return this->authenticated;
}

int User::getActiveAvatarId() {
    return this->activeAvatarId;
}

///Setters
void User::setUsername(const std::string &username) {
    this->username = username;
}


void User::setAuthenticated(bool b) {
    this->authenticated = b;
}

void User::setActiveAvatarId(int id) {
    this->activeAvatarId = id;
}

void User::reset() {
    this->username = "";
    this->authenticated = false;
    this->activeAvatarId = -1;
}

///User Message Container Operations
//deposits a message in the User's message container
void User::sendMessage (const std::string &message) {
    this->userMessageDeque.push_back(message);
}

//returns a concatenated string of all of User's messages
std::string User::getUserMessagesConcatenated() const{

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
bool User::isMessageEmpty() const{
    return this->userMessageDeque.empty();
}
