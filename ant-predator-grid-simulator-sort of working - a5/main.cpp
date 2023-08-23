#include <iostream>
#include <vector>
#include "Organism.h"
#include "Ant.h"
#include "Grid.h"
#include <unistd.h>
using namespace std;

Grid grid = Grid(100, 100);

// Displays board
void displayBoard() {
    cout << grid << endl;
}


void moveOrganisms() {
    // Move MaleDoodlebugs
    for (int i = 0; i < grid.gridHeight; i++) {
        for (int j = 0; j < grid.gridLength; j++) {
            if (grid.get_grid()[i][j]->getType() == "X") {
                grid.get_grid()[i][j]->move(grid.get_grid()[i][j], &grid);
            }
        }
    }
    // Move ants
    for (int i = 0; i < grid.gridHeight; i++) {
        for (int j = 0; j < grid.gridLength; j++) {
            if (grid.get_grid()[i][j]->getType() == "a") {
                grid.get_grid()[i][j]->move(grid.get_grid()[i][j], &grid);
            }
        }
    }
}


int main() {

    cout << "Input a for automatic or m for manual\n";
    char mode;
    cin >> mode;

    // Mode selection
    if (mode == 'a') {
        displayBoard();
        for (int i = 0; i < 50; i++) {
            moveOrganisms();
            grid.add_survive();
            displayBoard();
            cout << "\n Step: " << i << "\n";
            sleep(1);
        }
    }
    else if (mode == 'm') {
        displayBoard();
        for (int i = 0; i < 50; i++) {
            moveOrganisms();
            grid.add_survive();
            displayBoard();
            cout << "\n Step: " << i << "\n";
            cout << "Input enter to continue\n";
            // Gets cin input
            if (cin.get() == '\n') {

            }
        }
    }


}

