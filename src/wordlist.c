#include "wordlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_COUNT 200
#define MAX_WORD_LENGTH 20

static int currentWordLength = 0;
static char secretWord[MAX_WORD_LENGTH];

void chooseWord() {
    static char wordList[MAX_WORD_COUNT][MAX_WORD_LENGTH];
    static int initialized = 0;
    static int wordCount = 0;

    if (!initialized) {
        FILE *file = fopen("words.txt", "r");
        if (file == NULL) {
            perror("Error opening file");
            exit(1);
        }

        while (fgets(wordList[wordCount], MAX_WORD_LENGTH, file)) {
            wordList[wordCount][strcspn(wordList[wordCount], "\n")] = 0;
            wordCount++;
            if (wordCount >= MAX_WORD_COUNT) break;
        }
        fclose(file);
        initialized = 1;
    }

    srand(time(NULL));
    int index = rand() % wordCount;
    strcpy(secretWord, wordList[index]);

    currentWordLength = strlen(secretWord);
}

int getCurrentWordLength() {
    return currentWordLength;
}

const char *getSecretWord() {
    return secretWord;
}
