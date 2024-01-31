#include "game.h"
#include "wordlist.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

void initializeGameState(char *displayWord, int *lives) {
    chooseWord();
    for (int i = 0; i < getSecretWordLength(); i++) {
        displayWord[i] = '_';
    }
    displayWord[getSecretWordLength()] = '\0';
    *lives = MAX_LIVES;
}

void drawHangman(int lives) {
    printf("Lives left: %d\n", lives);
}

int processGuess(char guess, char *displayWord) {
    const char *secretWord = getSecretWord();
    int correctGuess = 0;
    for (int i = 0; secretWord[i] != '\0'; i++) {
        if (tolower(guess) == tolower(secretWord[i])) {
            displayWord[i] = secretWord[i];
            correctGuess = 1;
        }
    }
    return correctGuess;
}

int getSecretWordLength() {
    return getCurrentWordLength();
}