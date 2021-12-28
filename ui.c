#include "ui.h"
int MAX_GUESSES = 10;
char CHOICES2[] = {'r', 'g', 'y', 'm', 'w', 'b'};

void initTable(char table[MAX_GUESSES][8])
{
    for (int i = 0; i < MAX_GUESSES; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            table[i][j] = ' ';
        }
    }
}

void render(char table[MAX_GUESSES][8])
{
    int inc = 0;
    int numOfColorPair;
    printw("+");
    for (int i = 0; i < 4; i++)
    {
        printw("----+");
    }
    printw("\n");
    for (int j = MAX_GUESSES; j > 0; j--)
    {
        printw("|");
        for (int i = 0; i < 8; i++)
        {
            if (i > 3)
            {
                printw(" %c ", table[j - 1][i]);
            }
            else if((numOfColorPair = getColorPair(table[j-1][i])) != -1){
                attron(COLOR_PAIR(numOfColorPair));
                printw(" %c  ", table[j - 1][i]);
                attroff(COLOR_PAIR(numOfColorPair));
                printw("|");
            }
            else
            {
                printw(" %c  |", table[j - 1][i]);
            }
        }
        printw("\n");
        printw("+");
        for (int i = 0; i < 4; i++)
        {
            printw("----+");
        }
        printw("\n");
        inc++;
    }
}

int getColorPair(char symbol){
    for (int i = 0; i < 6; i++){
        if (CHOICES2[i] == symbol){
            return i + 1;
        }
    }
    return -1;
}