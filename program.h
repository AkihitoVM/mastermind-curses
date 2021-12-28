#ifndef _PROGRAM_H
#define _PROGRAM_H

#define GUESS_WRONG '_'
#define GUESS_RIGHT 'X'
#define GUESS_PRESENT '*'
#define SOLUTION_LENGTH 4

/**
 * Generate secret code
 * 
 * Generates secret code, which consists 4 random letter from array of CHOICES. 
 * No two letters in the code combination can be same!
 * The length of generated code is set by the constant length.
 * @return Pointer to the random generated code as string of given length.
 */
char *generateSolution();

/**
 * Checks if array of symbols picked contain symbol choice.
 * @param picked array of current elements.
 * @param choice search symbol. 
 * @return true, if array contain the symbol, false otherwise.
 */
bool contains(char picked[4], char choice);

/**
 * Matches the solution to user input 
 * The length of analyzed code is set by the constant length.
 * @param solution pointer to correct solution of game
 * @param guess pointer to user's guess
 * @return Pointer to the analyzed guess.
 */
char *analyzeGuess(char *solution, char *guess);

/**
 * Checks if array of symbols picked contain symbol choice.
 * @param guess_1 array of current elements.
 * @param solution search symbol. 
 * @return true, if each element from guess_1 array equal to element which stands in same location 
 * in array solution, false otherwise.
 */
bool equals(char *guess_1, char *solution);

/**
 * Get current timestamp in milliseconds
 * @return the number of milliseconds
 */
long long current_timestamp();

/**
 * Get input from user and validate
 * @param table array of elements
 * @param row pointer to number of rows
 */
void input_from_user(char table[10][8], int *row);

/**
 * Get last user input from table via row number
 * @param table array of elements
 * @param row pointer to number of rows
 * @return Pointer to the last four elements in table.
 */
char *getLastUserInput(char table[10][8], int row);

/**
 * Get final result of user input
 * @param analysis 
 * @return Pointer to the final analyzed guess.
 */
char *getFinalAnalyzedGuess(char *analysis);

/**
 * Insert analyzed guess into game table
 * @param table array of elements
 * @param row pointer to number of rows
 * @param analyzedGuess analyzed guess from user input
 */
void insertAnalyzedGuessToTable(char table[10][8], int row, char* analyzedGuess);

#endif
