#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include "program.h"
#include "ui.h"
const char CHOICES[] = {'r', 'g', 'y', 'm', 'w', 'b'};

bool contains(char picked[4], char choice)
{
    for (int i = 0; i < 4; i++)
    {
        if (picked[i] == choice)
        {
            return true;
        }
    }
    return false;
}

char *generateSolution()
{
    srand(time(NULL));
    char *picked = calloc(SOLUTION_LENGTH, sizeof(char));
    int i = 0;
    while (strlen(picked) < SOLUTION_LENGTH)
    {
        char choice = CHOICES[rand() % 6];
        if (contains(picked, choice))
        {
            continue;
        }
        picked[i] = choice;
        i++;
    }
    return picked;
}

bool inChoices(char c)
{
    for (int i = 0; i < 6; i++)
    {
        if (CHOICES[i] == c)
        {
            return true;
        }
    }
    return false;
}

void input_from_user(char table[10][8], int *row)
{
    int c;
    int iterator = 0;
    while (iterator < 4)
    {
        c = getch();
        int i;
        if (inChoices(c))
        {
            for (i = 0; i < iterator; i++)
            {
                if (c == table[*row][i])
                {
                    clear();
                    break;
                }
            }
            if (i == iterator)
            {

                clear();
                table[*row][iterator] = c;
                iterator++;
            }
        }
        else
        {
            clear();
            attron(COLOR_PAIR(7));
            printw("rgymwb ONLY!!!\n");
            attroff(COLOR_PAIR(7));
        }

        render(table);
    }

    *row += 1;
}

char *analyzeGuess(char *solution, char *guess)
{
    char *result = calloc(4, sizeof(char));
    for (int i = 0; i < 4; i++)
    {
        if (solution[i] == guess[i])
        {
            result[i] = GUESS_RIGHT;
        }
        else if (contains(solution, guess[i]))
        {
            result[i] = GUESS_PRESENT;
        }
        else
        {
            result[i] = GUESS_WRONG;
        }
    }
    return result;
}

bool equals(char *guess_1, char *solution)
{
    for (int i = 0; i < 4; i++)
    {
        if (guess_1[i] != solution[i])
        {
            return false;
        }
    }
    return true;
}

long long current_timestamp()
{
    struct timeval te;
    gettimeofday(&te, NULL);
    long long milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000;
    return milliseconds;
}

char *getLastUserInput(char table[10][8], int row)
{
    char *guess_1 = calloc(4, sizeof(char));
    for (int i = 0; i < 4; i++)
    {
        guess_1[i] = table[row - 1][i];
    }
    return guess_1;
}

char *getFinalAnalyzedGuess(char *analysis)
{
    char* b = calloc(4, sizeof(char));
    
    int c = 0;
    for (int i = 0; i < 4; i++)
    {
        if (analysis[i] == 'X')
        {
            b[c] = analysis[i];
            c++;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        if (analysis[i] == '*')
        {
            b[c] = analysis[i];
            c++;
        }
    }
    return b;
}

void insertAnalyzedGuessToTable(char table[10][8], int row, char* b)
{
    int x = 4;
    for (int i = 0; i < strlen(b); i++)
    {
        table[row - 1][x] = b[i];
        x++;
    }
}
