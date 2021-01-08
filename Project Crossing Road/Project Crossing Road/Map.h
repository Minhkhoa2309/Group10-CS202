#ifndef Map_h
#define Map_h

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <cmath>
#include "Player.h"
#include "Position.h"
#include "Lanes.h"
#include "Level.h"
#include "Obstacle.h"
using namespace std;


class Map {
	const int width = 115, height = 36;
	char map[40][125];
	Player player;
	Lanes rowsData;
	Level level;
	int t = 0;
public:
	Map();
	~Map() = default;

	void printBorder();
	void printMap();
	
	void drawMap();
	void redrawMap();

	int draw(Position pos, char** shape, int w, int h); // draw from position pos(x, y) shape(w, h) | 1: ok, 0: go out of map

	void drawPlayer();
	void deleteOldPlayer();

	void initializeNewState(); // intialize a new map base on level, reset player state
	void randomNextState(); // generate new enemies base on level and push to rows
	
	void updatePosPlayer(char moving);

	void printCongrats();
	bool printLevelUp();
	void nextLevel();

	bool isEnd();
	bool isWin();

	bool saveGame(string file);
	bool loadGame(string file);
	void printInt(int x, ofstream& outfile);
	int readInt(ifstream& infile);
};


#endif