//
// Created by Dev on 2019-01-24.
//

#include "../include/UserManager.h"

void UserManager::addUser(User &newUser) {
    Users.insert({newUser.getConnection().id, newUser});
}

void UserManager::removeUser(const uintptr_t &conId) {
    Users.erase(conId);
}

User& UserManager::findUser(const uintptr_t &conId) {

    auto user = Users.find(conId);
    if(user != Users.end()){
        return user->second;
    }

}

void UserManager::Authenticate(const uintptr_t &conId, const std::string& userInfo) {

    auto user = Users.find(conId);
    if(user != Users.end()){
        user->second.setAuthenticated(true);
    }

}

void UserManager::Logout(const uintptr_t &conId) {
    auto user = Users.find(conId);
    if(user != Users.end()){
        user->second.setAuthenticated(false);
    }
}

std::deque<networking::Message> UserManager::buildOutgoing(const std::string& log) {
    std::deque<networking::Message> outgoing;
    for (auto user : Users) {
        outgoing.push_back({user.second.getConnection(), log});
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
