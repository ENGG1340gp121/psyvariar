Player.o: Player.cpp Player.h
	g++ -c Player.cpp

Enemy.o: Enemy.cpp Enemy.h
	g++ -c Enemy.cpp

Enemies.o: Enemies.cpp Enemies.h
	g++ -c Enemies.cpp

Bullet.o: Bullet.cpp Bullet.h
	g++ -c Bullet.cpp

game.o: game.cpp game.h Player.h Enemies.h Bullet.h
	g++ -c game.cpp

main.o: main.cpp game.h
	g++ -c main.cpp

main: main.o game.o Player.o Enemies.o Enemy.o Bullet.o
	g++ main.o game.o Player.o Enemies.o Enemy.o Bullet.o -o main -lcurses

clean:
	rm -f *.o main

.PHONY: clean
