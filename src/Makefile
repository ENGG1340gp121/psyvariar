Load_background.o: Load_background.cpp Load_background.h
	g++ -std=c++11 -c Load_background.cpp

Player.o: Player.cpp Player.h
	g++ -std=c++11 -c Player.cpp

Enemy.o: Enemy.cpp Enemy.h
	g++ -std=c++11 -c Enemy.cpp

Enemies.o: Enemies.cpp Enemies.h
	g++ -std=c++11 -c Enemies.cpp

Obstacle.o: Obstacle.cpp Obstacle.h
	g++ -std=c++11 -c Obstacle.cpp

Obstacles.o: Obstacles.cpp Obstacles.h
	g++ -std=c++11 -c Obstacles.cpp

Bullet.o: Bullet.cpp Bullet.h
	g++ -std=c++11 -c Bullet.cpp

Board.o: Board.cpp Board.h Player.h
<<<<<<< HEAD
	g++ -c Board.cpp
=======
	g++ -std=c++11 -c Board.cpp
>>>>>>> 1e4794c7dc295c9ea111ef2fe4ea1ca27e77f334

game.o: game.cpp game.h Player.h Enemies.h Bullet.h Board.h Obstacles.h
	g++ -std=c++11 -c game.cpp

<<<<<<< HEAD
menu.o: menu.cpp menu.h
	g++ -c menu.cpp

main.o: main.cpp game.h Load_background.h Board.h menu.h
	g++ -c main.cpp

main: main.o game.o Player.o Enemies.o Enemy.o Bullet.o Load_background.o Board.o menu.o
	g++ main.o game.o Player.o Enemies.o Enemy.o Bullet.o Load_background.o Board.o menu.o -o main -lcurses
=======
main.o: main.cpp game.h Load_background.h Board.h
	g++ -std=c++11 -c main.cpp

main: main.o game.o Player.o Enemies.o Enemy.o Bullet.o Load_background.o Board.o Obstacle.o Obstacles.o
	g++ -std=c++11 main.o game.o Player.o Enemies.o Enemy.o Bullet.o Load_background.o Board.o Obstacle.o Obstacles.o -o main -lcurses
>>>>>>> 1e4794c7dc295c9ea111ef2fe4ea1ca27e77f334

clean:
	rm -f *.o main

.PHONY: clean
