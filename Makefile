CC=gcc
CFLAGS=-Iinclude
BUILD_DIR=build

# OS-specific part
ifeq ($(OS),Windows_NT)
    MKDIR=if not exist "$(BUILD_DIR)" mkdir
    RM=rd /s /q
else
    MKDIR=mkdir -p
    RM=rm -rf
endif

hangman: $(BUILD_DIR)/main.o $(BUILD_DIR)/game.o $(BUILD_DIR)/wordlist.o
	$(CC) -o $(BUILD_DIR)/hangman $(BUILD_DIR)/main.o $(BUILD_DIR)/game.o $(BUILD_DIR)/wordlist.o

$(BUILD_DIR)/main.o: src/main.c
	$(MKDIR) $(BUILD_DIR)
	$(CC) $(CFLAGS) -c src/main.c -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/game.o: src/game.c include/game.h
	$(CC) $(CFLAGS) -c src/game.c -o $(BUILD_DIR)/game.o

$(BUILD_DIR)/wordlist.o: src/wordlist.c include/wordlist.h
	$(CC) $(CFLAGS) -c src/wordlist.c -o $(BUILD_DIR)/wordlist.o

clean:
	$(RM) $(BUILD_DIR)