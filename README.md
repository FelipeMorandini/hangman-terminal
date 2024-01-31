# Hangman Game in C

This project is a simple implementation of the classic Hangman game in C. The game selects a random word from a list, and the player tries to guess it by suggesting letters within a certain number of guesses.

## Structure

The project is organized into several files for modularity:

- `main.c`: Contains the main game loop and user interaction logic.
- `game.c`: Handles the game state, drawing of the hangman, and processing guesses.
- `wordlist.c`: Manages the word list and random word selection.
- `game.h`: Header file for game-related functions.
- `wordlist.h`: Header file for word list management functions.

## Building the Project

This project uses a Makefile for easy compilation. To build the project, navigate to the project directory and run the following command:

```bash
make
```

This will compile the source files and generate the executable in the build directory.

## Requirements

- GCC (GNU Compiler Collection) for compiling the source code.
- A standard C library.
- Make (for building the project using the Makefile).

## Running the Game

After building the project, you can run the game using:

```bash
./build/hangman
```

## Game Play

The game will display a series of underscores representing the hidden word.
You will be prompted to guess a letter.
If the guessed letter is in the word, it will be revealed in its correct position(s).
If the guessed letter is not in the word, the number of remaining lives will decrease.
The game continues until the word is fully guessed or the player runs out of lives.

## Contributing

Contributions to this project are welcome. You can contribute in several ways:

- Improving the source code for efficiency or readability.
- Adding new features or enhancements.
- Updating or expanding the word list.
- Feel free to fork this repository and submit a pull request with your changes.

## License

This project is open-source and available under the MIT License.

Enjoy playing and improving the Hangman game!