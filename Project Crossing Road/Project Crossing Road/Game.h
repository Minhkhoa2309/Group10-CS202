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
	Map map;
	bool isLoaded = false;
	bool isPausing = false;
public:
	Game() = default;
	~Game() = default;

	void menu();
	void gameSettings();
	bool crashedMenu();

	bool newGame();
	bool continueGame();
	bool operatingGame();
	void loading();

	vector<string> getAllFilename(const std::string& name);
	bool loadGameMenu();
	bool saveGameMenu();


	void togglePauseGame();
	void toggleMute();
	void toggleHard();

	// void menu(bool& isFinish);
	// void pauseMenu(int cmd);
	// void saveGame();
	// void playGame(bool& is_finish);
	// void testThread();
};

// void SubThread(Game* cg, bool* IS_RUNNING, bool* isPausing, bool* exitFlag);
#endif // cGame
