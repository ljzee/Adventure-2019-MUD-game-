//
// Created by Dev on 2019-03-16.
//

#ifndef ADVENTURE2019_ASSOCIATIONCONTROLLER_H
#define ADVENTURE2019_ASSOCIATIONCONTROLLER_H

#include <iostream>
#include <unordered_map>

/**
 * AssociationController Class:
 *
 * - maintains the association between a connectionid to characterid
 * - association is created when player creates a new character or select an existing character
 * - association is removed when player logouts or disconnects
 * - can get characterid from connectionid and vice versa
 *
 */

class AssociationController {
public:

    void addAssociation(uintptr_t connectionId, int characterId);
    void removeAssociation(uintptr_t connectionId);
    uintptr_t getConnectionId(int characterId);
    int getCharacterId(uintptr_t connectionId);

private:
    std::unordered_map<uintptr_t, int> connectionIdToCharacterId;
    std::unordered_map<int, uintptr_t> characterIdToConnectionId;

};


#endif //ADVENTURE2019_ASSOCIATIONCONTROLLER_H
