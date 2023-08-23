//
// Created by datsu on 12/2/2022.
//

#ifndef TEST_FEMALEDOODLEBUG_H
#define TEST_FEMALEDOODLEBUG_H
#include "Organism.h"


class FemaleDoodlebug : public Organism {
private:
    int starveCount;
    int breedCount;
public:
    int getStarveCount() {return starveCount;};
    void setStarveCount(int newCount) {starveCount = newCount;};

    int getBreedCount() {return breedCount;};
    void setBreedCount(int newCount) {breedCount = newCount;};

    string getType() {return "Y";};

    virtual void move(Organism *fd, Grid *grid);

    FemaleDoodlebug();
};


#endif //TEST_FEMALEDOODLEBUG_H
