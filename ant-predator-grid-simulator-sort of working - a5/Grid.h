//
// Created by datsu on 11/14/2022.
//

#pragma once

#include <vector>
#include <iostream>
#include "Organism.h"
using namespace std;
class Organism;

class Grid {

private:
    vector<vector<Organism*>> grid;
public:
    int gridLength = 100;
    int gridHeight = 100;

    Grid();

    Grid(int length, int height);

    vector<vector<Organism*>> &get_grid() {
        return grid;
    }

    void makeGrid();

    friend ostream &operator<<(ostream &out, Grid grid);

    void reset_move();

    void add_survive();
};