//
// Created by Dev on 2019-03-22.
//

#include "constants.h"

namespace ADMIN_CONSTANTS {
    extern const std::string WELCOME_PROMPT = "Welcome Aboard!\nLogin by typing !LOGIN <username> <password> or !REGISTER <username> <password>";
    extern const std::string SELECT_PROMPT = "To select an existing avatar: !SELECT [avatar_name]\nTo create a new avatar: !NEW [avatar_name]";
    extern const std::string SELECT_SUCCESS = "You've selected a character";
}

namespace AUTH_CONSTANTS{
    extern const std::string MALFORMED = "Malformed authenticate call message.";
    extern const std::string ALREADY_LOGGED_IN = "This user is already logged on elsewhere.";
    extern const std::string LOGIN = "You've successfully logged in.";
    extern const std::string LOGOUT = "You have successfully logged out.";
    extern const std::string LOGIN_PROMPT =  "Login with !LOGIN <user> <pass> or register with !REGISTER <user> <pass>";
    extern const std::string INCORRECT_CREDENTIALS = "Username or password is incorrect. Please try again.";
    extern const std::string REGISTER_SUCCESS = "You've successfully registered and logged in.";
    extern const std::string USERNAME_TAKEN = "This username is already being used. Please, choose a different one.";
    extern const std::string REGISTER_MALFORMED = "Malformed register call message. Please type !REGISTER <username> <password>.";
}

namespace WORLD_CONSTANTS{
    extern const std::string CHARACTER_CREATE_SUCCESS = "You have successfully created a new character.";
    extern const std::string CHARACTER_NAME_TAKEN = "The character name you chose has already been taken.";
}
