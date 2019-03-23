//
// Created by Dev on 2019-03-06.
//

#ifndef ADVENTURE2019_CLONABLE_H
#define ADVENTURE2019_CLONABLE_H

#include <memory>


class Clonable {

public:
virtual ~Clonable() = 0;
virtual std::unique_ptr<Clonable> clone() = 0;

};


#endif //ADVENTURE2019_CLONABLE_H
