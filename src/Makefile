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
	g++ -std=c++11 -c Board.cpp

game.o: game.cpp game.h Player.h Enemies.h Bullet.h Board.h Obstacles.h
	g++ -std=c++11 -c game.cpp

main.o: main.cpp game.h Load_background.h Board.h
	g++ -std=c++11 -c main.cpp

main: main.o game.o Player.o Enemies.o Enemy.o Bullet.o Load_background.o Board.o Obstacle.o Obstacles.o
	g++ -std=c++11 main.o game.o Player.o Enemies.o Enemy.o Bullet.o Load_background.o Board.o Obstacle.o Obstacles.o -o main -lcurses

clean:
	rm -f *.o main

.PHONY: clean
