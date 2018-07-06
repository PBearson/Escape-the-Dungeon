all: escape_the_dungeon clean

main.o: main.cpp
	g++ -c main.cpp

weapons_logic.o: weapons_logic.cpp
	g++ -c weapons_logic.cpp

game_assets.o: game_assets.cpp
	g++ -c game_assets.cpp

player_logic.o: player_logic.cpp
	g++ -c player_logic.cpp

primary_assets.o: primary_assets.cpp
	g++ -c primary_assets.cpp

escape_the_dungeon: main.o primary_assets.o game_assets.o player_logic.o weapons_logic.o
	g++ main.o weapons_logic.o primary_assets.o game_assets.o player_logic.o -o escape_the_dungeon -lsfml-graphics -lsfml-window -lsfml-system

clean: 
	rm -f *.o

