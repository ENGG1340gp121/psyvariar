# broforce
## Team members
* Liu Che(3036030972), Github: [che330](https://github.com/che330)
* Shi Boao(3035973787)
* Fan Zhenyi(3035974054)
*
* 


## Description





## Features and coding requirements
* We will generate enemies that will appear in random locations (Generation of random game sets or events)
* The player, enemies, bullets, ... are all implemented as `class` (Data structures for storing game status)
* We use `std::vector` to maintain all the bullets and enemies inside the frame. (Dynamic memory management)
* File IO: we use File IO to store and read the rank of scores of players.
* Our program code is splitted into multuple files based on class. (Program codes in multiple files)

## Libraries
We mainly use `curses.h` library.

## How to compile and run
**Make sure the size of you terminal is at least 150 x 50 to display properly.**
### Step 1.
```bash
cd src # Enter the ./src directory
```
### Step 2.
```bash
make main # Compile and create ./main
```
### Step 3.
```bash
./main # run the program
```
