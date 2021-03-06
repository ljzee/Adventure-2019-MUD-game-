#ifndef WORLD_H
#define WORLD_H

#include <unordered_map>
#include <set>
#include <memory>
#include <vector>
#include "RoomController.h"
#include "CharacterController.h"
#include "AssociationController.h"
#include "Server.h"

class World {

public:
    enum CharacterCreationStatus {
        name_taken = 0, creation_success = 1
    };

    enum MovementStatus {
        movement_success = 0, door_not_exist, door_locked, movement_failed
    };

    enum TargetPlayerStatus {
        in_room = 0, not_in_room
    };

    World(std::unique_ptr<RoomController> roomController,
          std::unique_ptr<CharacterController> characterController,
          std::unique_ptr<AssociationController> associationController);

    ///Character creation/selection methods
    std::pair<enum CharacterCreationStatus, int> createCharacter(const std::string& name);
    std::string selectCharacter(networking::Connection connection, int characterId);

    ///Disassociate a connection with a player on logout/disconnect,
    ///TODO: move character from active character storage to non-active character storage
    void removeAssociation(networking::Connection connection);

    ///Called when no arguments to look are specified or when character moves to new room
    std::string getRoomEntitiesDescription(int roomId);

    ///Communicate Commands
    std::vector<uintptr_t> getRelevantPlayerConnections(networking::Connection messageCreator, const std::string& communicationMethod);
    std::pair<enum TargetPlayerStatus, uintptr_t> getTargetPlayerConnection(networking::Connection messageCreator, const std::string& characterName);

    ///Move commands
    enum MovementStatus moveCharacter(std::string direction, networking::Connection connection);

    std::string getCharacterName(networking::Connection connection);
    int getCharacterLocation(networking::Connection connection);

private:

   ///look inside .h files of controllers for more in-depth descriptions of their responsibilities
   std::unique_ptr<RoomController> roomController;
   std::unique_ptr<CharacterController> characterController;
   std::unique_ptr<AssociationController> associationController;

   std::string placeCharacter(int characterId);
   std::string getRoomCharactersDescription(int roomId);
};

#endif //WORLD_H
