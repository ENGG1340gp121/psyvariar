Player.o: Player.cpp Player.h
	g++ -c Player.cpp -lncurses

Enemy.o: Enemy.cpp Enemy.h
	g++ -c Enemy.cpp -lncurses

game.o: game.cpp game.h Player.h Enemy.h
	g++ -c game.cpp -lncurses

main.o: main.cpp game.h
	g++ -c main.cpp -lncurses

main: main.o game.o Player.o Enemy.o
	g++ -lncurses main.o game.o Player.o Enemy.o -o main
