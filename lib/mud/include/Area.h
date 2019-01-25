//
// Created by Andrea Renney on 2019-01-24.
//

#ifndef ADVENTURE2019_AREA_H
#define ADVENTURE2019_AREA_H

//Using JSON file's AREA object, which only includes "Name" as a field???
//Ex:   "AREA": {
//      "name": "Mirkwood"
//      }
class Area {

    private:

        std::string dummy_name;

    public:

        Area();
        std::string get_dummy_name();

};


#endif //ADVENTURE2019_AREA_H
