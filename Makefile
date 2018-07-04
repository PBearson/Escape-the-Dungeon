all: escape_the_dungeon clean

main.o: main.cpp
	g++ -c main.cpp

game_assets.o: game_assets.cpp
	g++ -c game_assets.cpp

escape_the_dungeon: main.o game_assets.o
	g++ main.o game_assets.o -o escape_the_dungeon -lsfml-graphics -lsfml-window -lsfml-system

clean: 
	rm -f *.o

