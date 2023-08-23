//
// Created by datsu on 11/14/2022.
//

#ifndef TEST_ANT_H
#define TEST_ANT_H
#include <string>
#include <vector>
#include "Organism.h"


using namespace std;

class Grid;

class Ant: public  Organism {
public :
    Ant();

    string getType() {return "a";};

    virtual void move(Organism* ant, Grid* grid);
};


#endif //TEST_ANT_H
