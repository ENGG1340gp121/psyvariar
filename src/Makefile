Load_background.o: Load_background.cpp Load_background.h
	g++ -std=c++11 -c Load_background.cpp

menu.o: menu.cpp menu.h save.h game.h globals.h
	g++ -std=c++11 -c menu.cpp

save.o: save.cpp save.h
	g++ -std=c++11 -c save.cpp

Player.o: Player.cpp Player.h Bullet.h
	g++ -std=c++11 -c Player.cpp

Enemy.o: Enemy.cpp Enemy.h
	g++ -std=c++11 -c Enemy.cpp

Enemies.o: Enemies.cpp Enemies.h Enemy.h
	g++ -std=c++11 -c Enemies.cpp

Obstacle.o: Obstacle.cpp Obstacle.h
	g++ -std=c++11 -c Obstacle.cpp

Obstacles.o: Obstacles.cpp Obstacles.h Obstacles.h
	g++ -std=c++11 -c Obstacles.cpp

Bullet.o: Bullet.cpp Bullet.h
	g++ -std=c++11 -c Bullet.cpp

Board.o: Board.cpp Board.h
	g++ -std=c++11 -c Board.cpp

game.o: game.cpp game.h Enemies.h Bullet.h Board.h Player.h
	g++ -std=c++11 -c game.cpp

main.o: main.cpp game.h Load_background.h menu.h
	g++ -std=c++11 -c main.cpp

main: main.o game.o Player.o Enemies.o Enemy.o Bullet.o Load_background.o Board.o save.o Obstacle.o Obstacles.o menu.o
	g++ -std=c++11 main.o game.o Player.o Enemies.o Enemy.o Bullet.o Load_background.o Board.o save.o Obstacle.o Obstacles.o menu.o -o main -lcurses

clean:
	rm -f *.o main

.PHONY: clean
