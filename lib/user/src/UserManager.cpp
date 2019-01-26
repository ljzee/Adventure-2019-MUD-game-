//
// Created by Dev on 2019-01-24.
//

#include "../include/UserManager.h"
#include <regex>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>

using namespace boost;

//adds a new user
void UserManager::addUser(User &newUser) {
    Users.insert({newUser.getConnection().id, newUser});
}

//remove a current user, on logout or disconnect
void UserManager::removeUser(const uintptr_t &conId) {
    Users.erase(conId);
}

//find a user, returns a copy only
User& UserManager::findUser(const uintptr_t &conId) {

    auto user = Users.find(conId);
    if(user != Users.end()){
        return user->second;
    }

}

//authenticate a user when user sends !LOGIN
void UserManager::Authenticate(const uintptr_t &conId, const std::string& userInfo) {
    auto user = Users.find(conId);
    std::cout << "CALL: AUTHENTICATE WITH MESSAGE: " << userInfo  << "\n";
    auto login_pattern = std::regex("!LOGIN [a-zA-Z0-9!@#$%^&*()_+=-]+ [[a-zA-Z0-9!@#$%^&*()_+=-]+");

    if (!(std::regex_match(userInfo, login_pattern)) ){
        std::cout << "Malformed authenticate call message.\n";
        return;
    }
    std::string userName;
    std::string pwd;
    try {
        boost::char_separator<char> sep{" "};
        tokenizer<boost::char_separator<char>> tok(userInfo, sep);
        tokenizer<boost::char_separator<char>>::iterator beg = tok.begin();
        beg++;

        userName = *beg;
        beg++;

        pwd = *beg;
        std::cout << userName << " " << pwd << "\n";
    } catch (const std::exception& e){
        std::cout << "Malformed authenticate call message.\n";
    }
    if(userName != "" && user != Users.end()){
        // New User Behavior
        if (user->second.getUsername() == "") {
            user->second.setUsername(userName);
            user->second.setPassword(pwd);
        }
        user->second.setAuthenticated(true);
    }
}

//logout an authenticated user
void UserManager::Logout(const uintptr_t &conId) {
    auto user = Users.find(conId);
    if(user != Users.end()){
        user->second.setAuthenticated(false);
    }
}

//second message to a particular user
void UserManager::sendMessage(const uintptr_t &conId, std::string message) {
    auto user = Users.find(conId);
    user->second.sendMessage(message);
}

//build a deque of all messages to be sent to each user
std::deque<networking::Message> UserManager::buildOutgoing() {
    std::deque<networking::Message> outgoing;
    for (auto user=Users.begin(); user != Users.end(); user++) {
        if(!user->second.isMessageEmpty()){
            outgoing.push_back({user->second.getConnection(), user->second.getUserMessagesConcatenated()});
            user->second.clearMessages();
        }
    }
    return outgoing;
}


void UserManager::printAllUsers() {
    std::cout << "Connected Users: " << std::endl;
    for (auto user : Users)
        std::cout << user.second.getConnection().id
        << " username:"
        << user.second.getUsername()
        << " authenticated:" << user.second.isAuthenticated()
        << std::endl;
}
