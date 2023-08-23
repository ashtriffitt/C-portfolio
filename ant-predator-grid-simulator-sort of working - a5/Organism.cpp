//
// Created by datsu on 11/14/2022.
//

#include "Organism.h"
#include "Grid.h"
#include <iostream>

using namespace std;

Organism::Organism(int posx, int posy, string orgType) {
    this->posy = posy;
    this->posx = posx;
    this->orgType = orgType;
    stepCount = 0;

    oldx = -5;
    oldy = -5;

    justMoved = false;

    notMoveCount = 0;
}

void Organism::move(Organism* org, Grid* grid) {

}
