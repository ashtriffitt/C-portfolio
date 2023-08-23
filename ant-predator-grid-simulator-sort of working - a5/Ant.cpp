//
// Created by datsu on 11/14/2022.
//

#include "Ant.h"
#include <iostream>
#include "Grid.h"
using namespace std;

// Default constructor.
Ant::Ant() : Organism(0, 0, "a") {

}

// Move function
void Ant::move(Organism* ant, Grid* grid) {

    Organism* empty = new Organism(ant->getPosx(), ant->getPosy(), ".");
    Ant* newAnt = new Ant();

    int oldx = ant->getPosx();
    int oldy = ant->getPosy();

    ant->setOldx(oldx);
    ant->setOldy(oldy);

    int randx = rand() % 3;
    int randy = rand() % 3;

    randx--;
    randy--;

    int newposx = ant->getPosx() + randx;
    int newposy = ant->getPosy() + randy;

    if (newposx > 99) {
        newposx = 0;
    }
    else if (newposx < 0) {
        newposx = 99;
    }
    if (newposy > 99) {
        newposy = 0;
    }
    else if (newposy < 0) {
        newposy = 99;
    }

    // Starving and moving
    // Moving
    if (grid->get_grid()[newposx][newposy]->getType() == ".") {
        grid->get_grid()[ant->getPosx()][ant->getPosy()] = empty;

        ant->setPosx(newposx);
        ant->setPosy(newposy);

        grid->get_grid()[ant->getPosx()][ant->getPosy()] = ant;

        ant->setNotMoveCount(0);
    }
    // Starving
    else {
        ant->setNotMoveCount(ant->getNotMoveCount() + 1);
        if (ant->getNotMoveCount() == 4) {
            grid->get_grid()[ant->getPosx()][ant->getPosy()] = empty;
        }
    }

    // Reproduction
    if (ant->getStepCount() == 5) {
        newAnt->setPosx(oldx);
        newAnt->setPosy(oldy);
        newAnt->setType("a");
        grid->get_grid()[oldx][oldy] = newAnt;

        ant->setStepCount(0);
    }
}