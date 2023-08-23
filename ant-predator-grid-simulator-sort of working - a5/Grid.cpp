//
// Created by datsu on 11/30/2022.
//

#include "Grid.h"
#include "Ant.h"
#include "MaleDoodlebug.h"
#include "FemaleDoodlebug.h"

class MaleDoodlebug;


// default constructor for grid
Grid::Grid() {}

// construct grid of given length and height
Grid::Grid(int length, int height) {
    // initialize array based on given length and height
    for (int i = 0; i < height; i++) {
        vector<Organism*> row;
        for (int j = 0; j < length; j++) {
            row.push_back(new Organism(i, j, "."));
        }
        grid.push_back(row);
    }
    makeGrid();
}

// function to add all organisms to the empty grid
void Grid::makeGrid() {
    srand(time(nullptr));
    // add random ants
    for (int i = 0; i < 70; i++) {
        int random_row = 0 + (rand() % (gridLength - 0));
        int random_col = 0 + (rand() % (gridHeight - 0));
        Ant *ant = new Ant();
        grid[random_row][random_col] = ant;
        ant->setPosx(random_row);
        ant->setPosy(random_col);
        ant->setType("a");
    }

    // add doodle bugs
    for (int i = 0; i < 12; i++) {
        int random_row = 0 + (rand() % (gridHeight - 0));
        int random_col = 0 + (rand() % (gridLength - 0));
        int gender[2] = {0, 1};
        int rand_gender = rand() % 2;
        int gender_select = gender[rand_gender];

        if (gender_select == 0) {
            MaleDoodlebug* bug = new MaleDoodlebug();
            grid[random_row][random_col] = bug;
            bug->setPosx(random_row);
            bug->setPosy(random_col);
            bug->setType("X");
        } else if (gender_select == 1) {
            FemaleDoodlebug* fBug = new FemaleDoodlebug();
            grid[random_row][random_col] = fBug;
            fBug->setPosx(random_row);
            fBug->setPosy(random_col);
        }
    }
}

// after each time step add 1 to how long an organism has survived for
void Grid::add_survive() {
    for (int i = 0; i < gridHeight; i++) {
        for (int j = 0; j < gridLength; j++) {
            // add one to each organism's survival count
            grid[i][j]->setStepCount(grid[i][j]->getStepCount() + 1);
        }
    }
}

// overloaded stream operator to print the grid
 ostream& operator<< (ostream& out, Grid grid) {
    // iterate through grid
    for (int i = 0; i < grid.gridHeight; i++) {
        for (int j = 0; j < grid.gridLength; j++) {
            // output the organism type
            out << (*grid.get_grid()[i][j]).getType();
        }
        cout << '\n';
    }
    return out;
}