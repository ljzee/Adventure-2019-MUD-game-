#ifndef WORLD_H
#define WORLD_H

#include <unordered_map>
#include <set>
#include <memory>
#include <boost/bimap.hpp>
#include <vector>
#include <algorithm>
#include "RoomController.h"
#include "CharacterController.h"
#include "AssociationController.h"
#include "Server.h"

class World {

public:
    enum CharacterCreationStatus {
        name_taken = 0, creation_success = 1
    };

    World(std::unique_ptr<RoomController> roomController,
          std::unique_ptr<CharacterController> characterController,
          std::unique_ptr<AssociationController> associationController);

    ///Character creation methods
    std::pair<enum CharacterCreationStatus, int> createCharacter(networking::Connection connection, const std::string& name);
    std::string placeNewCharacter(networking::Connection connection);

    ///Cleanup methods on logout or disconnect
    void removeAssociation(networking::Connection connection);

    std::string getRoomCharactersDescription(int roomId);
    std::string getRoomEntitiesDescription(int roomId);

    int getCharacterLocation(networking::Connection connection);

    bool hasDoor(int roomId, const std::string& doorName);
    int getDoorTargetRoomId(int roomId, const std::string& doorName);
    bool moveCharacter(int from, int to, networking::Connection connection);

private:

   std::unique_ptr<RoomController> roomController;
   std::unique_ptr<CharacterController> characterController;
   std::unique_ptr<AssociationController> associationController;

};

#endif //WORLD_H
