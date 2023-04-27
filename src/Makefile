Load_background.o: Load_background.cpp Load_background.h
	g++ -c Load_background.cpp

Player.o: Player.cpp Player.h
	g++ -c Player.cpp

Enemy.o: Enemy.cpp Enemy.h
	g++ -c Enemy.cpp

Enemies.o: Enemies.cpp Enemies.h
	g++ -c Enemies.cpp

Obstacle.o: Obstacle.cpp Obstacle.h
	g++ -c Obstacle.cpp

Obstacles.o: Obstacles.cpp Obstacles.h
	g++ -c Obstacles.cpp

Bullet.o: Bullet.cpp Bullet.h
	g++ -c Bullet.cpp

Board.o: Board.cpp Board.h Player.h
	g++ -c Board.cpp

game.o: game.cpp game.h Player.h Enemies.h Bullet.h Board.h Obstacles.h
	g++ -c game.cpp

main.o: main.cpp game.h Load_background.h Board.h
	g++ -c main.cpp

main: main.o game.o Player.o Enemies.o Enemy.o Bullet.o Load_background.o Board.o Obstacle.o Obstacles.o
	g++ main.o game.o Player.o Enemies.o Enemy.o Bullet.o Load_background.o Board.o Obstacle.o Obstacles.o -o main -lcurses

clean:
	rm -f *.o main

.PHONY: clean
