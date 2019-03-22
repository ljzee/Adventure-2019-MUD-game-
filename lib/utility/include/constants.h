//
// Created by Dev on 2019-03-22.
//

#ifndef ADVENTURE2019_CONSTANTS_H
#define ADVENTURE2019_CONSTANTS_H

#endif //ADVENTURE2019_CONSTANTS_H

#include <fstream>
#include <iostream>
#include <sstream>

namespace ADMIN_CONSTANTS {
    extern const std::string WELCOME_PROMPT;
    extern const std::string SELECT_PROMPT;
    extern const std::string SELECT_SUCCESS;
}

namespace AUTH_CONSTANTS{
    extern const std::string MALFORMED;
    extern const std::string ALREADY_LOGGED_IN;
    extern const std::string LOGIN;
    extern const std::string LOGOUT;
    extern const std::string LOGIN_PROMPT;
    extern const std::string INCORRECT_CREDENTIALS;
    extern const std::string REGISTER_SUCCESS;
    extern const std::string USERNAME_TAKEN;
    extern const std::string REGISTER_MALFORMED;
}

namespace WORLD_CONSTANTS{
    extern const std::string CHARACTER_CREATE_SUCCESS;
    extern const std::string CHARACTER_NAME_TAKEN;
}