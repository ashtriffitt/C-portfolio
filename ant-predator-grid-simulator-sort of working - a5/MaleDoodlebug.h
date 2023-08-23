//
// Created by datsu on 12/2/2022.
//

#ifndef TEST_MALEDOODLEBUG_H
#define TEST_MALEDOODLEBUG_H
#include <string>
#include <vector>
#include "Organism.h"

class MaleDoodlebug : public Organism {
private:
    int starveCount;
    int breedCount;
public:
    int getStarveCount() {return starveCount;};
    void setStarveCount(int newCount) {starveCount = newCount;};

    int getBreedCount() {return breedCount;};
    void setBreedCount(int newCount) {breedCount = newCount;};

    string getType() {return "X";};

    MaleDoodlebug();

    virtual void move(Organism *md, Grid *grid);
};


#endif //TEST_MALEDOODLEBUG_H
