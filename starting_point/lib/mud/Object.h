//
// Created by Andrea Renney on 2019-01-24.
//

#ifndef ADVENTURE2019_OBJECT_H
#define ADVENTURE2019_OBJECT_H

#include <vector>
#include <string>

//Using JSON file's OBJECTS object
//Ex:   "id": 8800,
//      "keywords": [
//        "pool"
//      ],
//      "shortdesc": "a pool",
//      "longdesc": [
//        "A pool of crystal-clear water fills this clearing."
//      ],
//      "extra": [
//        {
//          "keywords": [
//            "pool"
//          ],
//          "desc": [
//            "It looks tasty. Have a drink!"
//          ]
//        }
//      ]
class Object {

    private:

        int ID;
        //Not really sure what "keywords" are but it seems like there could
        //be multiple, thus the vector
        vector<std::string> keywords;

        std::string shortdesc;

        std::string longdesc;

        //A vector of vectors of strings for "extra" - within the extra vector, it will hold vectors
        //for "keywords" (could be multiple, thus the vector), and "desc"
        //This is implemented in a constructor I guess?
        vector<vector<std::string>> extra;

    public:

        Object();
        int getID();
        vector<std::string> getKeywords();
        std::string getShortDesc();
        std::string getLongDesc();
        vector<vector<std::string>> getExtra();

};


#endif //ADVENTURE2019_OBJECT_H
