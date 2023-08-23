//
// Created by datsu on 11/14/2022.
//

#ifndef TEST_ORGANISM_H
#define TEST_ORGANISM_H
#include <string>
#include <vector>


using namespace std;

class Grid;

class Organism {
    int oldx;
    int oldy;
int posx;
int posy;
int stepCount;

bool justMoved;

string orgType;

int notMoveCount;

public :
    int getPosx() {return posx;};

    int getPosy() {return posy;};

    void setPosx(int newpos) {posx = newpos;};

    void setPosy(int newpos) {posy = newpos;};

    int getOldx() {return posx;};

    int getOldy() {return posy;};

    void setOldx(int newpos) {oldx = newpos;};

    void setOldy(int newpos) {oldy = newpos;};

    int getJustMoved() {return justMoved;};

    void setJustMoved(bool b) {justMoved = b;};

    int getStepCount() { return stepCount;};

    void setStepCount(int newstep) { stepCount = newstep;};

    int getNotMoveCount() { return notMoveCount;};

    void setNotMoveCount(int newstep) { notMoveCount = newstep;};

    string getType() {return orgType;};

    void setType(string newtype) {orgType = newtype;};

    virtual void move(Organism* ant, Grid* grid);

    Organism(int posx, int posy, string orgType);
};


#endif //TEST_ORGANISM_H
