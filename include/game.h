#ifndef GAME_H
#define GAME_H

#define MAX_LIVES 6
#define MAX_WORD_LENGTH 20

void initializeGameState(char *displayWord, int *lives);
void drawHangman(int lives);
int processGuess(char guess, char *displayWord);
int getSecretWordLength();

#endif