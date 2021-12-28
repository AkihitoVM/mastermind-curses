#ifndef _UI_H
#define _UI_H
#include <curses.h>

/**
 * Renders the game
 * @param table the array of elements to print
 */
void render(char table[10][8]);

/**
 * Initiate game field
 * @param table array of elements
 */
void initTable(char table[10][8]);

/**
 * Initiate game field
 * @param symbol symbol
 * @return number of color pair if symbol contain in CHOICES array, -1 otherwise.
 */
int getColorPair(char symbol);

#endif
