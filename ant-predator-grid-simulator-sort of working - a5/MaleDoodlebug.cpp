//
// Created by datsu on 12/2/2022.
//

#include "MaleDoodlebug.h"
#include "Grid.h"

MaleDoodlebug::MaleDoodlebug() : Organism(0, 0, "X") {

}

void MaleDoodlebug::move(Organism* md, Grid* grid) {
    Organism* empty = new Organism(md->getPosx(), md->getPosy(), ".");
    MaleDoodlebug* newMd = new MaleDoodlebug();

    int oldx = md->getPosx();
    int oldy = md->getPosy();

    md->setOldx(oldx);
    md->setOldx(oldx);
    md->setOldy(oldy);

    int newposx = md->getPosx();
    int newposy = md->getPosy();

    // Sets position to be moved to if there are no ants around
    int nesw = rand() % 4;

    if (nesw == 0) {
        if (md->getPosx() == 9) {
            newposx = 0;
        }
        else {
           newposx = md->getPosx() + 1;
        }
    }
    if (nesw == 1) {
        if (md->getPosx() == 0) {
            newposx = 99;
        }
        else {
          newposx = md->getPosx() - 1;
        }
    }
    if (nesw == 2) {
        if (md->getPosy() == 99) {
            newposy = 0;
        }
        else {
            newposy = md->getPosy() + 1;
        }
    }
    if (nesw == 3) {
        if (md->getPosy() == 0) {
            newposy = 99;
        }
        else {
            newposy = md->getPosy() - 1;
        }
    }

    // Moves doodlebug based on if there are ants around
    if (md->getPosx() == 99) {
        if (grid->get_grid()[0][md->getPosy()]->getType() == "a") {
            grid->get_grid()[md->getPosx()][md->getPosy()] = empty;

            md->setPosx(0);

            grid->get_grid()[md->getPosx()][md->getPosy()] = md;
        }
    }
    else if (md->getPosx() == 0) {
        if (grid->get_grid()[99][md->getPosy()]->getType() == "a") {
            grid->get_grid()[md->getPosx()][md->getPosy()] = empty;

            md->setPosx(99);

            grid->get_grid()[md->getPosx()][md->getPosy()] = md;
        }
    }
    else if (md->getPosy() == 99) {
        if (grid->get_grid()[md->getPosx()][0]->getType() == "a") {
            grid->get_grid()[md->getPosx()][md->getPosy()] = empty;

            md->setPosy(0);

            grid->get_grid()[md->getPosx()][md->getPosy()] = md;
        }
    }
    else if (md->getPosy() == 0) {
        if (grid->get_grid()[md->getPosx()][99]->getType() == "a") {
            grid->get_grid()[md->getPosx()][md->getPosy()] = empty;

            md->setPosy(99);

            grid->get_grid()[md->getPosx()][md->getPosy()] = md;
        }
    }
    else if (grid->get_grid()[md->getPosx() + 1][md->getPosy()]->getType() == "a") {
        grid->get_grid()[md->getPosx()][md->getPosy()] = empty;

        md->setPosx(md->getPosx() + 1);

        grid->get_grid()[md->getPosx()][md->getPosy()] = md;
    }
    else if (grid->get_grid()[md->getPosx() - 1][md->getPosy()]->getType() == "a") {
        grid->get_grid()[md->getPosx()][md->getPosy()] = empty;

        md->setPosx(md->getPosx() - 1);

        grid->get_grid()[md->getPosx()][md->getPosy()] = md;
    }
    else if (grid->get_grid()[md->getPosx()][md->getPosy() + 1]->getType() == "a") {
        grid->get_grid()[md->getPosx()][md->getPosy()] = empty;

        md->setPosy(md->getPosy() + 1);

        grid->get_grid()[md->getPosx()][md->getPosy()] = md;
    }
    else if (grid->get_grid()[md->getPosx()][md->getPosy() - 1]->getType() == "a") {
        grid->get_grid()[md->getPosx()][md->getPosy()] = empty;

        md->setPosy(md->getPosy() - 1);

        grid->get_grid()[md->getPosx()][md->getPosy()] = md;
    }
    else {
        grid->get_grid()[md->getPosx()][md->getPosy()] = empty;

        md->setPosx(newposx);
        md->setPosy(newposy);

        grid->get_grid()[md->getPosx()][md->getPosy()] = md;
        if (grid->get_grid()[newposx][newposy]->getType() == "a") {
            md->setNotMoveCount(0);
        }
        else {
            md->setNotMoveCount(md->getNotMoveCount() + 1);
        }
    }

    // Starving
    if (md->getNotMoveCount() == 5) {
        grid->get_grid()[md->getPosx()][md->getPosy()] = empty;
    }

    // Reproduction
    if (md->getStepCount() == 0) {
        newMd->setPosx(oldx);
        newMd->setPosy(oldy);
        newMd->setType("X");
        grid->get_grid()[oldx][oldy] = newMd;

        md->setStepCount(0);
    }
}
