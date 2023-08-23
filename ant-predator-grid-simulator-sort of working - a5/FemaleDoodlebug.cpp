//
// Created by datsu on 12/2/2022.
//

#include "FemaleDoodlebug.h"
#include "Grid.h"

// Defualt constructor
FemaleDoodlebug::FemaleDoodlebug() : Organism(0, 0, "Y") {

}

void FemaleDoodlebug::move(Organism* fd, Grid* grid) {
    Organism* empty = new Organism(fd->getPosx(), fd->getPosy(), ".");
    FemaleDoodlebug* newFb = new FemaleDoodlebug;

    int oldx = fd->getPosx();
    int oldy = fd->getPosy();

    fd->setOldx(oldx);
    fd->setOldy(oldy);

    int newposx = fd->getPosx();
    int newposy = fd->getPosy();

    // Sets position to be moved to if there are no ants around
    int nesw = rand() % 4;

    if (nesw == 0) {
        if (fd->getPosx() == 9) {
            newposx = 0;
            if (fd->getPosy() == 9) {
                newposy = 0;
            }
            else {
                newposy = fd->getPosy() + 1;
            }
        }
        else {
            newposx = fd->getPosx() + 1;
            if (fd->getPosy() == 9) {
                newposy = 0;
            }
            else {
                newposy = fd->getPosy() + 1;
            }
        }
    }
    if (nesw == 1) {
        if (fd->getPosx() == 0) {
            newposx = 99;
        }
        else {
            newposx = fd->getPosx() - 1;
        }
    }
    if (nesw == 2) {
        if (fd->getPosy() == 99) {
            newposy = 0;
        }
        else {
            newposy = fd->getPosy() + 1;
        }
    }
    if (nesw == 3) {
        if (fd->getPosy() == 0) {
            newposy = 99;
        }
        else {
            newposy = fd->getPosy() - 1;
        }
    }

    // Moves doodlebug based on if there are ants around
    if (fd->getPosx() == 99) {
        if (grid->get_grid()[0][fd->getPosy()]->getType() == "a") {
            grid->get_grid()[fd->getPosx()][fd->getPosy()] = empty;

            fd->setPosx(0);

            grid->get_grid()[fd->getPosx()][fd->getPosy()] = fd;
        }
    }
    else if (fd->getPosx() == 0) {
        if (grid->get_grid()[99][fd->getPosy()]->getType() == "a") {
            grid->get_grid()[fd->getPosx()][fd->getPosy()] = empty;

            fd->setPosx(99);

            grid->get_grid()[fd->getPosx()][fd->getPosy()] = fd;
        }
    }
    else if (fd->getPosy() == 99) {
        if (grid->get_grid()[fd->getPosx()][0]->getType() == "a") {
            grid->get_grid()[fd->getPosx()][fd->getPosy()] = empty;

            fd->setPosy(0);

            grid->get_grid()[fd->getPosx()][fd->getPosy()] = fd;
        }
    }
    else if (fd->getPosy() == 0) {
        if (grid->get_grid()[fd->getPosx()][99]->getType() == "a") {
            grid->get_grid()[fd->getPosx()][fd->getPosy()] = empty;

            fd->setPosy(99);

            grid->get_grid()[fd->getPosx()][fd->getPosy()] = fd;
        }
    }
    else if (grid->get_grid()[fd->getPosx() + 1][fd->getPosy()]->getType() == "a") {
        grid->get_grid()[fd->getPosx()][fd->getPosy()] = empty;

        fd->setPosx(fd->getPosx() + 1);

        grid->get_grid()[fd->getPosx()][fd->getPosy()] = fd;
    }
    else if (grid->get_grid()[fd->getPosx() - 1][fd->getPosy()]->getType() == "a") {
        grid->get_grid()[fd->getPosx()][fd->getPosy()] = empty;

        fd->setPosx(fd->getPosx() - 1);

        grid->get_grid()[fd->getPosx()][fd->getPosy()] = fd;
    }
    else if (grid->get_grid()[fd->getPosx()][fd->getPosy() + 1]->getType() == "a") {
        grid->get_grid()[fd->getPosx()][fd->getPosy()] = empty;

        fd->setPosy(fd->getPosy() + 1);

        grid->get_grid()[fd->getPosx()][fd->getPosy()] = fd;
    }
    else if (grid->get_grid()[fd->getPosx()][fd->getPosy() - 1]->getType() == "a") {
        grid->get_grid()[fd->getPosx()][fd->getPosy()] = empty;

        fd->setPosy(fd->getPosy() - 1);

        grid->get_grid()[fd->getPosx()][fd->getPosy()] = fd;
    }
    else {
        grid->get_grid()[fd->getPosx()][fd->getPosy()] = empty;

        fd->setPosx(newposx);
        fd->setPosy(newposy);

        grid->get_grid()[fd->getPosx()][fd->getPosy()] = fd;

        if (grid->get_grid()[newposx][newposy]->getType() == "a") {
            fd->setNotMoveCount(0);
        }
        else {
            fd->setNotMoveCount(fd->getNotMoveCount() + 1);
        }
    }

    // Starving
    if (fd->getNotMoveCount() == 5) {
        grid->get_grid()[fd->getPosx()][fd->getPosy()] = empty;
    }

    // Reproduction
    if (fd->getStepCount() == 5) {
        newFb->setPosx(oldx);
        newFb->setPosy(oldy);
        newFb->setType("Y");
        grid->get_grid()[oldx][oldy] = newFb;

        fd->setStepCount(0);

    }
}