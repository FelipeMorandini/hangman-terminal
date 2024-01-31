#include "game.h"
#include <stdio.h>
#include <string.h>

int main() {
    int lives, gameOver;
    char guess;

    char playAgain = 'y';
    while (playAgain == 'y') {
        char displayWord[MAX_WORD_LENGTH];
        memset(displayWord, '_', getSecretWordLength());
        displayWord[getSecretWordLength()] = '\0';

        initializeGameState(displayWord, &lives);
        gameOver = 0;

        while (!gameOver) {
            printf("\n\n%s\n", displayWord);
            drawHangman(lives);
            printf("\nGuess a letter: ");
            scanf(" %c", &guess);

            if (!processGuess(guess, displayWord)) {
                lives--;
                if (lives <= 0) {
                    gameOver = 1;
                    printf("\nSorry, you lost!\n");
                    printf("Word was: %s\n", getSecretWord());
                }
            } else {
                if (strchr(displayWord, '_') == NULL) {
                    gameOver = 1;
                    printf("\nCongratulations! You've won!\n");
                    printf("The word is: %s\n", getSecretWord());
                }
            }
        }

        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    }

    return 0;
}
