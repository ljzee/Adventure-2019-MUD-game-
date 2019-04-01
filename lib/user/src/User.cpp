//
// Created by Dev on 2019-01-17.
//

#include "../include/User.h"

///Constructor
User::User(networking::Connection connection)
        : username(),
          currentConnection(connection),
          authenticated(false),
          hasActiveAvatar(false)
{
    //std::cout << "New user has been created" << std::endl;
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

bool User::getHasActiveAvatar() {
    return this->hasActiveAvatar;
}

///Setters
void User::setUsername(const std::string &username) {
    this->username = username;
}


void User::setAuthenticated(bool b) {
    this->authenticated = b;
}

void User::setHasActiveAvatar(bool b) {
    this->hasActiveAvatar = b;
}

void User::reset() {
    this->username = "";
    this->authenticated = false;
    this->hasActiveAvatar = false;
    this->ownedCharacters.clear();
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

void User::addNewCharacter(std::pair<std::string, int> characterNameAndId){
    ownedCharacters.push_back(characterNameAndId);
}

int User::getOwnedCharacterId(const std::string& name){
    auto result = std::find_if(ownedCharacters.begin(), ownedCharacters.end(),
                               [name](const std::pair<std::string, int> & p) -> bool {return p.first == name; });
    if(result != ownedCharacters.end()){
        return result->second;
    }
    return -1;
}

std::string User::getOwnedCharacterInfo(){
    std::string ownedCharacterInfo = std::string("Your characters: ");
    for(auto character : ownedCharacters){
        ownedCharacterInfo = ownedCharacterInfo + character.first + " ";
    }
    return ownedCharacterInfo;
}