/* well.cpp ---
 *
 * Filename: well.cpp
 * Description:
 * Author: Bryce
 * Maintainer: Adeel Bhutta
 * Created: Tue Sep  6 11:08:59 2016
 * Last-Updated: 01-10-2021
 *           By: Adeel Bhutta
 *     Update #: 0
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

#include <cstdlib>
#include <ncurses.h>
#include "well.hpp"

well_t *init_well(int upper_left_x, int upper_left_y, int width, int height)
{
  well_t *w;
  w = (well_t *)malloc(sizeof(well_t));
  w->upper_left_x = upper_left_x;
  w->upper_left_y = upper_left_y;
  w->width = width;
  w->height = height;
  w->draw_char = '#';
  w->color[0] = 0;
  w->color[1] = 0;
  w->color[2] = 0;
  return (w);
}

void draw_well(well_t *w)
{
  int row_counter, column_counter;
  // Draw left side of well
  for (column_counter = w->upper_left_y; column_counter <= (w->upper_left_y + w->height); column_counter++)
  {
    // mvprintw(column_counter,w->upper_left_x,"%c",w->draw_char);
    attron(COLOR_PAIR(4));
    mvaddch(column_counter, w->upper_left_x, '#');
    attroff(COLOR_PAIR(4));
  }

  // Draw right side of well
  for (column_counter = w->upper_left_y; column_counter <= (w->upper_left_y + w->height); column_counter++)
  {
    // mvprintw(column_counter,(w->upper_left_x + w->width),"%c",w->draw_char);
    attron(COLOR_PAIR(4));
    mvaddch(column_counter, (w->upper_left_x + w->width), '#');
    attroff(COLOR_PAIR(4));
  }

  // Draw Bottom of well
  for (row_counter = w->upper_left_x; row_counter <= (w->upper_left_x + w->width); row_counter++)
  {
    // mvprintw(w->upper_left_y + w->height,row_counter,"%c",w->draw_char);
    attron(COLOR_PAIR(4));
    mvaddch((w->upper_left_y + w->height), row_counter, '#');
    attroff(COLOR_PAIR(4));
  }
}

well_t *changeWellSize(int upper_left_x, int upper_left_y, int width, int height, well_t *w)
{

  w->upper_left_x = upper_left_x;
  w->upper_left_y = upper_left_y;
  if (width < 10)
    w->width = 10;
  else
    w->width = width;

  w->height = height;

  return (w);
}

void undraw_well(well_t *w)
{
  int row_counter, column_counter;
  // Undraw left side of well
  for (column_counter = w->upper_left_y; column_counter <= (w->upper_left_y + w->height); column_counter++)
  {
    mvprintw(column_counter, w->upper_left_x, " ", w->draw_char);
  }

  // Undraw right side of well
  for (column_counter = w->upper_left_y; column_counter <= (w->upper_left_y + w->height); column_counter++)
  {
    mvprintw(column_counter, (w->upper_left_x + w->width), " ", w->draw_char);
  }

  // Undraw Bottom of well
  for (row_counter = w->upper_left_x; row_counter <= (w->upper_left_x + w->width); row_counter++)
  {
    mvprintw(w->upper_left_y + w->height, row_counter, " ", w->draw_char);
  }
}

void redraw_pieces(well_t *well)
{
  int color;
  int counter = 0;
  for (int i = well->height; i >= 0; i--)
  {
    for (int j = 29; j <= 52; j++)
    {
      color = mvinch(i, j) & A_COLOR;
      if (color == COLOR_PAIR(1))
      {
        mvprintw(i, j, " ");
        attron(COLOR_PAIR(1));
        mvaddch(i + 1, j, '%');
        attroff(COLOR_PAIR(1));
      }
      if (color == COLOR_PAIR(2))
      {
        mvprintw(i, j, " ");
        attron(COLOR_PAIR(2));
        mvaddch(i + 1, j, '%');
        attroff(COLOR_PAIR(2));
      }
      if (color == COLOR_PAIR(3))
      {
        mvprintw(i, j, " ");
        attron(COLOR_PAIR(3));
        mvaddch(i + 1, j, '%');
        attroff(COLOR_PAIR(3));
      }
      if (color == COLOR_PAIR(5))
      {
        mvprintw(i, j, " ");
        attron(COLOR_PAIR(5));
        mvaddch(i + 1, j, '%');
        attroff(COLOR_PAIR(5));
      }
      if (color == COLOR_PAIR(6))
      {
        mvprintw(i, j, " ");
        attron(COLOR_PAIR(6));
        mvaddch(i + 1, j, '%');
        attroff(COLOR_PAIR(6));
      }
      if (color == COLOR_PAIR(7))
      {
        mvprintw(i, j, " ");
        attron(COLOR_PAIR(7));
        mvaddch(i + 1, j, '%');
        attroff(COLOR_PAIR(7));
      }
    }
  }
}

int prune_well(well_t *well)
{
  int counter = 0;
  int color;
  int row_counter = 0;
  for (int i = 0; i <= well->height; i++)
  {
    counter = 0;
    for (int j = 29; j <= 52; j++)
    {
      color = mvinch(i, j) & A_COLOR;
      if ((color == COLOR_PAIR(1)) || (color == COLOR_PAIR(2)) || (color == COLOR_PAIR(3)) 
      || (color == COLOR_PAIR(5)) || (color == COLOR_PAIR(6)) || (color == COLOR_PAIR(7)))
      {
        counter++;
        // mvprintw(10,10,"%i", counter);
        // undraw_well(well);
        if (counter == 24)
        {
          counter = 0;
          row_counter++;
          mvprintw(10, 10, "%i", row_counter);
          for (int x = 29; x <= 52; x++)
          {
            mvprintw(i, x, " ");
          }
          redraw_pieces(well);
        }
      }
    }
  }
  mvprintw(11, 10, "%i", row_counter);
  return row_counter;
}
/* well.cpp ends here */
