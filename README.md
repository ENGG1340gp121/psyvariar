# ENGG1340 Game : Psyvariar
## Team Members
* Liu Che (3036030972)
  * Github: [che330](https://github.com/che330)

* Shi Boao (3035973787)
  * Github: [aoibosh](https://github.com/aoibosh)

* Fan Zhenyi (3035974054)
* Mao Junkai (3035973696)
* Sang Ziheng (3035974638)

## Description

Our game is a text-based airplane battle game called `Psyvariar`. You will control an aircraft and engage in intense aerial combat. during combat, you need to dodge bullets fired by enemy planes and shoot bullets at enemy planes in order to destroy them. You also need to avoid knocking into enemy planes and obstacles. Otherwise, your aircraft will crash immediately. 

## Rules

#### Basic Settings

1. **Control**: Use the arrow keys (up, down, left, right) to move your aircraft (If you press and hold space, the plane will keep moving). Press Spacebar to shoot bullets (hold the Spacebar to shoot continuously). 
2. **Score**: You will get 10 scores every time you destroy an enemy plane.
3. **Health**: You will have 10 health points (HP) at the beginning. Your HP will decrease by 1 for receiving every hit by an enemy plane's bullet. Your HP will be cleared to zero if your aircraft crashes into enemy planes or obstacles.
4. **Game over**: The game will end as soon as the HP of your aircraft equals to or less than zero.

#### Special Settings

1. The weapon will overheat and temporarily lie off after you shoot more than 5 bullets in a row, which means you can not shoot over 5 bullets without break.
2. You can press the "F" key to clear all enemy planes and enemy planes' bullets from the screen, but obstacles cannot be cleared. This is just a plug-in, in case you feel this game is too hard.
3. The shape of your aircraft will change and upgrade as you destroy more enemy planes in the game. You will also get honors as you destroy a certain number of enemy planes.
4. The scores of different users are stored in a rank board, which can be viewed by selecting the "Rank Board" option in the menu. 

#### Game Interface

The game interface mainly consists of three parts.

1. Combat interface: The combat interface is on the top left side. It takes up most of the screen. You can control an aircraft and battle with enemy planes here.
2. Player interface: The player interface is on the right side of the screen. It displays your score and the honors you get. It will also prompt when the weapon is overheating, or your HP is below a certain level. 
3. Aircraft interface: The aircraft interface is at the bottom left of the screen. It displays the current HP and shape of your aircraft. 

## Code Requirement

* **Generation of random game sets or events**

  Enemies and obstacles are generated from the right randomly.

* **Data structures for storing game status**

  Player, Enemy, Bullet, Obstacle, etc. are all stored in `class`. Also, `struct` is used to record the shape of figure (player, enemy, obstacle)

* **Dynamic memory management**

  We use `std::vector` to maintain all the bullets and enemies inside the frame. When a sub-routine is finished, we use `vec.clear()` to release the memory. 

* **File input/output** 

  We use File IO to store and read the rank of scores of history players, making a ranking board.

* **Program codes in multiple files**

  We set different `.cpp` and `.h` files to deal with specific `class`. Each `class` can be used in different programs, making it efficient. Our program code is split into multiple files based on class.

* **Proper indentation and naming styles**

  Our good and straightforward naming styles

  `int HP, Level, weapon, x, y;`

  ```c++
  bool check_inside();
  void move(int c);
  void move_up();
  bool shoot();
  void get_damage(int value);
  void draw(WINDOW* win);
  void gun_heat_annealing();
  ```

* **In-code documentation**

  "what it does", "what the inputs are", "what the outputs are" are satisfied.
  
  ```c++
  // this function is used to initialize the bullet
  // _x, _y are the initially coordinate of bullet
  // _LX, _LY, _RX, _RY are the screen size
  // _sym is the symbol of figure
  Bullet::Bullet(int _x, int _y, int _LX, int _LY, int _RX, int _RY, char _sym)
  // this function is used to move the bullet for one unit
  // velocity is bullet's moving velocity
  // direction means bullet moves from left or right
  void Bullet::move(int velocity, int direction)
  // Generate an enemy thet is that is to the right of the frame
  // returns the generated enemy
  Enemy Enemies::generate_enemy()
  ```

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

```shell
./main 1 # if you want to skip the Loading_Background, add anything behind ./main to skip
```

