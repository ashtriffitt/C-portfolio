#include <cstdlib>
#include <ncurses.h>
#include <math.h>


int compute_score(int previous_score, int lines_cleared) {
    int current_score;
    current_score = previous_score + pow(lines_cleared, 2);
    return current_score;
}


