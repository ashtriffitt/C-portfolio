/* game.cpp ---
 *
 * Filename: game.cpp
 * Description:
 * Author: Bryce
 * Maintainer: Adeel Bhutta
 * Created: Tue Sep  6 11:08:59 2016
 * Last-Updated: 01-10-2021
 *           By: Adeel Bhutta
 *     Update #: 20
 * Keywords:
 * Compatibility:
 *
 */

/* Commentary:
 *
 *
 *
 */

/* Change log:
 *
 *
 */

/* Copyright (c) 2016 IUB
 *
 * All rights reserved.
 *
 * Additional copyrights may follow
 */

/* Code: */
// Elizabeth McCaffrey
// Ashton Triffitt
// 10/18/2022
// Assignment 03 Milestone 1

// TO DO:
// - update score when line(s) is/are cleared (10pts)
// - save top 5 scores in scores.txt (15pts)
// - update game over scenario [now have 3 lives] (5pts

#include <unistd.h>
#include <ncurses.h>
#include <ctime>
#include <cstdlib>
#include "game.hpp"
#include "well.hpp"
#include "tetris.hpp"
#include "tetromino.hpp"
#include "key.hpp"
#include "string.h"
#include "score.hpp"
#include <time.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
//using namespace std;

void init_game(void)
{
  int x, y;
}

int game(void)
{

  start_color();
  static int state = INIT;
  tetromino_t *next = NULL;
  tetromino_t *current = NULL;
  well_t *w;
  int x, y;
  int c;
  unsigned long int a = 0;
  int arrow;
  struct timespec tim = {0, 1000000}; // Each execution of while(1) is approximately 1mS
  struct timespec tim_ret;
  int move_counter = 0;
  int move_timeout = BASE_FALL_RATE;
  ////////// added
  // is game paused
  bool paused = false;
  // number of lives
  int life_count = 3;
  // message to have user enter name
  char mesg[] = "ENTER YOUR NAME: ";
  char str[80];
  // message to have user select difficulty
  char difficulty[] = "SELECT DIFFICULTY:\n\t\tEASY [\'e\']\n\t\tHARD [\'h\']\n\t\t";
  char selection[2];
  // initialize drop speed to base
  int current_drop_speed = BASE_FALL_RATE;
  // clock to track program runtime
  clock_t time_elapsed;
  unsigned msElapsed;
  // random drop rate
  int rand_drop;
  // random drop rates to select from
  int drop_rates[6] = {500, 550, 600, 650, 700, 750};
  // timer
  int timer = 0;
  clock_t ticks;
  // score
  int score = 0;
  std::fstream scores;

  std::string high_scores;

  //std::vector<std::string<int>> high_scores_vector;
    std::vector<int> high_scores_vector;

  // main game loop
  while (1)
  {
    // game cases
    switch (state)
    {
    case INIT: // Initialize the game, only run one time
      initscr();
      getmaxyx(stdscr, y, x); // Get the screen dimensions
      // take in difficulty selection
      mvprintw(5, 30, "WELCOME TO TETRIS!");
      mvprintw(10, 30, "%s", difficulty);
      getstr(selection);
      clear();
      endwin();
      // take in username
      mvprintw(10, 20, "%s", mesg);
      getstr(str);
      clear();
      endwin();
      w = init_well(((x / 2) - (WELL_WIDTH / 2)), 1, WELL_WIDTH, WELL_HEIGHT);
      nodelay(stdscr, TRUE); // Do not wait for characters using getch.
      noecho();              // Do not echo input characters
      draw_well(w);
      // print players name and lives
      mvprintw(1, 3, "%s", str);
      mvprintw(2, 3, "LIVES: %i", life_count);
      // print current score
      mvprintw(3, 3, "SCORE: %i", score);
      // print game timer
      mvprintw(4, 3, "TIMER: %i", timer);
      srand(time(NULL)); // Seed the random number generator with the time. Used in create tet.
      if (*selection == 'e') {
        // keep original drop rates
      }
      else if (*selection == 'h') {
        // update to faster drop rates for harder level
        drop_rates[1] = 350;
        drop_rates[2] = 400;
        drop_rates[3] = 450;
        drop_rates[4] = 500;
        drop_rates[5] = 550;
        drop_rates[6] = 600;
      }
      else {
        // keep original drop rates
      }
      state = ADD_PIECE;
      break;
    case ADD_PIECE: // Add a new piece to the game
                    // add new piece have it fall (random drop rates), also add next piece to the side of the screen
                    // detect game over scenario before new piece is added (can it enter screen without collision)
      if (next)
      {
        // change current to next
        current = next;
        // undisplay next tet
        undisplay_tetromino(next);
        // place next tet on screen
        next = create_tetromino(w->upper_left_x - 14, w->upper_left_y + 5);
        // determine if tet can be placed on screen, if not gameover state
        if (move_tet(current, (w->upper_left_x + (w->width / 2)), w->upper_left_y) == MOVE_FAILED)
        {
          state = GAME_OVER;
          break;
        }
        // move tet to middle position
        move_tet(current, (w->upper_left_x + (w->width / 2)), w->upper_left_y);
      }
      else
      {
        // create and place current tet
        current = create_tetromino((w->upper_left_x + (w->width / 2)), w->upper_left_y);
        // create and place next tet
        next = create_tetromino((w->upper_left_x + (w->width / 2)), w->upper_left_y);
      }
      // display current tet
      display_tetromino(current);
      // display next tet
      move_tet(next, w->upper_left_x - 14, w->upper_left_y + 5);
      display_tetromino(next);
      state = MOVE_PIECE;
      break;
    case MOVE_PIECE: // Move the current
                     // only run if the game is not paused
      if (!paused)
      {
        // loop allows piece to be dropped down screen
        while (check_collision(current) == COLLIDE)
        {
          // determine time in ms
          time_elapsed = clock();
          msElapsed = time_elapsed / CLOCKS_PER_MS;

          if (life_count > 0)
          {
            ticks = clock();
            timer = ticks / CLOCKS_PER_SEC;
            //mvprintw(4, 3, "TIMER: %i", timer);
          }

          // time elapsed should be equivalent to the drop speed
          // subtracting a will reset msElapsed
          if (msElapsed - a == current_drop_speed)
          {
            // undisplay current
            undisplay_tetromino(current);
            // checking if move is possible
            if (move_tet(current, current->upper_left_x, current->upper_left_y + 1) == MOVE_FAILED)
            {
              display_tetromino(current);
              // prune well before new piece is added
              // well::prune_well(w);
              // mvprintw(3, 3, "SCORE: %i", compute_score(score, prune_well(w)));
              // add new piece once current has hit bottom
              state = ADD_PIECE;
              // resent msElapsed
              a = msElapsed;
              // assign new randome drop rate
              current_drop_speed = drop_rates[rand() % 6];

              // check for game over state
              if (current->upper_left_y == w->upper_left_y)
              {
                state = GAME_OVER;
                break;
              }
              break;
            }
            // move tet down
            else
            {
              move_tet(current, current->upper_left_x, current->upper_left_y + 1);
            }
            display_tetromino(current);
            a = msElapsed;
          }
          if ((arrow = read_escape(&c)) != NOCHAR)
          {
            switch (arrow) // once piece has collided with bottom ADDPIECE state must be returned to
            {
            case UP:
              mvprintw(10, 10, "UP            "); // rotate clockwise (undisplay, rotate, display)
              /////////////
              undisplay_tetromino(current);
              check_collision(current);
              rotate_cw(current);
              display_tetromino(current);
              break;
            case DOWN:
              mvprintw(10, 10, "DOWN          "); // rotate counter clockwise (undisplay, rotate, display)
              /////////////
              undisplay_tetromino(current);
              check_collision(current);
              rotate_ccw(current);
              display_tetromino(current);
              break;
            case LEFT:
              mvprintw(10, 10, "LEFT          "); // move left (check collision, move)
              /////////////
              undisplay_tetromino(current);
              check_collision(current);
              move_tet(current, current->upper_left_x - 1, current->upper_left_y);
              display_tetromino(current);
              break;
            case RIGHT:
              mvprintw(10, 10, "RIGHT         "); // move right (check collision, move)
              /////////////
              undisplay_tetromino(current);
              check_collision(current);
              move_tet(current, current->upper_left_x + 1, current->upper_left_y);
              display_tetromino(current);
              break;
            case REGCHAR:
              // mvprintw(10, 10, "REGCHAR 0x%02x", c); // quit with q (need to add x for quit, p for pause, spacebar for drop)
              if (c == 'q')
              {
                state = EXIT;
              }
              ///////////
              else if (c == 'x')
              {
                state = EXIT;
              }
              else if (c == 'p' && !paused)
              {
                paused = true;
                mvprintw(10, 13, "PAUSED");
                mvprintw(12, 9, "\'p\' to resume");
              }
              else if (c == 32) // 32 ASCII for space bar
              {
                // adjust drop rate to faster
                a = msElapsed;
                // assign drop speed to the drop rate
                current_drop_speed = DROP_RATE;
              }
            }
            if (move_counter++ >= move_timeout)
            {
              move_counter = 0;
              break;
            }
            break;
          }
        }
      }
      // if game is paused wait for user to reenter 'p' to resume
      //   NOTE: this part is buggy and requires pressing space after resuming to get the pieces moving again
      else if (paused && getch() == 'p')
      {
        // change pause state
        paused = false;
        mvprintw(10, 13, "      ");
        mvprintw(12, 9, "             ");
      }
      break;
    case EXIT:
      endwin();
      return (0);
      break;
    // game over case that will wait 10 secs till closing program
    case GAME_OVER:
      mvprintw(10, 10, "GAME OVER");
      if (getch() == 'q' || getch() == 'x') {
        state = EXIT;

        scores.open("scores.txt");

       while (std::getline(scores, high_scores)) {
        //high_scores_vector.push_back(high_scores);
       }
       std::sort(high_scores_vector.begin(), high_scores_vector.end());
       for (int i = 0; i < high_scores_vector.size(); i++) {
        if (score > high_scores_vector[i]) {
          high_scores_vector.pop_back();
          high_scores_vector.push_back(score);
        }
       }
       std::sort(high_scores_vector.begin(), high_scores_vector.end());
        //scores << "this is where the score would get passed in, we also need to figure out how we are gonna sort and replace the top scores.";
       scores.close();
      }
      else
      {

        //std::ofstream.scores("scores.txt");
        //scores << "this is where the score would get passed in, we also need to figure out how we are gonna sort and replace the top scores.";
        scores.close();
        sleep(10);
        state = EXIT;
      }
    }
  }
  refresh();
  nanosleep(&tim, &tim_ret);
}

/* game.cpp ends here */
