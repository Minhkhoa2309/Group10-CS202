#ifndef cGame_h
#define cGame_h


#include <iostream>
#include <fstream>
#include <thread>
//#include <dirent.h>

#include "ConsoleWindow.h"
#include "Player.h"
#include "Obstacle.h"
#include "Lanes.h"
#include "Map.h"

using namespace std;

class Game {
	bool isLoaded = false;
	Map map;
	bool isPausing = false;
public:

	Game() = default;

	~Game() = default;

	void gameSettings();

	void menu(bool& isFinish);

	bool newGame(); // start a new game, initialize cMap map

	bool continueGame();  //continue our game

	bool loadGameMenu(); // get file of cMap map

	bool operatingGame();

	void saveGameMenu(); //void saveGame(); // print file of cMap map

	void pauseMenu(int cmd);

	void togglePauseGame(); // toggle status of isPausing

	void toggleMute();

	void toggleHard();

	void gameOver();

	void playGame(bool& is_finish);

	void testThread();

	void loading();

	vector<string> getAllFilename(const std::string& name);

	void menu();

	bool crashedMenu();
};

void SubThread(Game* cg, bool* IS_RUNNING, bool* isPausing, bool* exitFlag);
#endif // cGame
