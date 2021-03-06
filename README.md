# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

## Additions to the starter code
The main addition I made to the snake game is storing the high score.
If the current user has the new high score, the program asks the user to provide it’s name. 

Below are the rubrics my program meets.
### Loops, Functions, I/O
* The project reads data from a file and process the data: [Game::ReadHighscoreFromFile()](https://github.com/mahtt/CppND-Capstone-Snake-Game/blob/86c50464c46c6f1556959d254ae4fae3fd8b413e/src/game.cpp#L36)
* The project writes data to a file: [Game::UpdateHighscore()](https://github.com/mahtt/CppND-Capstone-Snake-Game/blob/86c50464c46c6f1556959d254ae4fae3fd8b413e/src/game.cpp#L58)
* The project accepts user input and processes the input: [Game::AskPlayerForName()](https://github.com/mahtt/CppND-Capstone-Snake-Game/blob/86c50464c46c6f1556959d254ae4fae3fd8b413e/src/game.cpp#L67)

### Object Oriented Programming
* The project uses Object Oriented Programming techniques (e.g. appropriate access specifiers for class members, abstraction of implementation details, encapsulation of behavior): [player.h](https://github.com/mahtt/CppND-Capstone-Snake-Game/blob/86c50464c46c6f1556959d254ae4fae3fd8b413e/src/player.h#L6)

### Memory Managmnent
* The project uses smart pointers instead of raw pointers: [main.cpp](https://github.com/mahtt/CppND-Capstone-Snake-Game/blob/86c50464c46c6f1556959d254ae4fae3fd8b413e/src/main.cpp#L16)

### Concurrency
* The project uses multithreading: [game.cpp](https://github.com/mahtt/CppND-Capstone-Snake-Game/blob/86c50464c46c6f1556959d254ae4fae3fd8b413e/src/game.cpp#L14)

# Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.
