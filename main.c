//important because of usleep()
#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include "program.h"
#include "ui.h"

int main(int argc, char *argv[])
{
    int row = 0;
    int guesses = 1;
    char *solution = generateSolution();
    initscr();
    start_color();
    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_GREEN, COLOR_GREEN);
    init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(4, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(5, COLOR_WHITE, COLOR_WHITE);
    init_pair(6, COLOR_BLUE, COLOR_BLUE);
    init_pair(7, COLOR_BLACK, COLOR_RED);
    keypad(stdscr, TRUE);
    noecho();

    char table[10][8];
    initTable(table);
    clear();
    render(table);
    while (true)
    {
        if (guesses > 10)
        {
            printw("You've ran out of guesses! Better luck next time!\n");
            printw("Correct solution: %s\n", solution);
            printw("Enter any key \n");
            break;
        }
        input_from_user(table, &row);

        char *guess_1 = getLastUserInput(table, row);

        char *analysis = analyzeGuess(solution, guess_1);

        char* analyzedGuess = getFinalAnalyzedGuess(analysis);

        insertAnalyzedGuessToTable(table, row, analyzedGuess);

        clear();
        render(table);
        
        if (equals(guess_1, solution))
        {
            printw("You've guessed correctly, you win!\n");
            printw("Enter any key \n");
            break;
        }
        guesses++;
    }
    getch();
    endwin();
    return 0;
}