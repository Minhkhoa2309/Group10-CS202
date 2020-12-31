#include "Game.h"


void Game::gameSettings() {
	system("cls");

	const char* setting[3] = { "Difficulty", "Sound", "Back to Main Menu" };
	const char* current[2] = { "", "" };

	if (constantVar::isHard) { current[0] = "HARD"; }
	else { current[0] = "EASY"; }

	if (constantVar::isMute) { current[1] = "OFF"; }
	else { current[1] = "ON "; }

	const int y = 20;
	const int x = 25;

	int userPos = 0;
	int flag = 0;
	int color = rand() % 7 + 9;

	map.printBorder();

	bool newInput = true;
	while (1) {
		// always runs -> color flash
		if (newInput) {
			drawTitle();

			for (int i = 0; i < 3; ++i) {
				gotoXY(x, y + i);

				if (i == userPos) { TextColor(11); }
				else { TextColor(15); }
				
				cout << setting[i];
				if (i != 2) { cout << "\t" << current[i]; }
			}

			newInput = false;
		}
		if (_kbhit()) {
			newInput = true;

			char key = _getch();
			if (key == 'W' || key == 'w') {
				userPos = (userPos + 2) % 3;
			}
			else if (key == 'S' || key == 's') {
				userPos = (userPos + 1) % 3;
			}
			else if (key == 13) {
				switch (userPos) {
				case 0:
					toggleHard();

					if (constantVar::isHard) { current[0] = "HARD"; }
					else { current[0] = "EASY"; }

					if (!constantVar::isMute) {
						//PlaySound(TEXT("RING.wav"), NULL, SND_ASYNC);
						//PlaySound(TEXT("PUBG.wav"), NULL, SND_ASYNC);
					}

					break;
				case 1:
					toggleMute();

					if (!constantVar::isMute) {
						current[1] = "ON ";
						//PlaySound(TEXT("RING.wav"), NULL, SND_ASYNC);
						//PlaySound(TEXT("PUBG.wav"), NULL, SND_ASYNC);
					}
					else { current[1] = "OFF"; }

					break;
				case 2:
					system("cls");
					flag = 1;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					return;
				}
			}
		}
	}
}

void Game::menu() {
	const char* choice[4] = { "New Game", "Load Game", "Settings", "Quit" };
	const int x = 35, y = 20;

	//if (!constantVar::isMute) { PlaySound(TEXT("PUBG.wav"), NULL, SND_ASYNC); }

	int curPos = 0;
	bool newInput = true;
	while (true) {
		newInput = true;
		map.printBorder();

		//if (!constantVar::isMute) { PlaySound(TEXT("PUBG.wav"), NULL, SND_ASYNC); }

		while (true) {
			if (newInput) {
				for (int i = 0; i < 4; i++) {
					gotoXY(x, y + i);

					if (i == curPos) { TextColor(11); }
					else { TextColor(15); }

					cout << choice[i] << endl;
				}
				
				drawTitle();

				TextColor(7);

				newInput = false;
			}
			switch (inputKey()) {
				newInput = true;
				PlaySound(TEXT("RING.wav"), NULL, SND_ASYNC);
			case 'w':
			case 'W':
				newInput = true;
				curPos = (curPos + 3) % 4;
				break;
			case 's':
			case 'S':
				newInput = true;
				curPos = (curPos + 1) % 4;
				break;
			case 13:
				switch (curPos) {
				case 0:
					while (1) {
						loading();

						if (newGame()) {
							Sleep(1000);

							clrscr();
							map.printBorder();

							//if (!constantVar::isMute)PlaySound(TEXT("PUBG.wav"), NULL, SND_ASYNC);

							newInput = true;

							break;
						}
						else if (!crashedMenu()) {
							if (isLoaded) {
								map.~Map();
								new(&map) Map;
							}
							Sleep(1000);

							clrscr();
							map.printBorder();

							//if (!constantVar::isMute)PlaySound(TEXT("PUBG.wav"), NULL, SND_ASYNC);

							newInput = true;
							break;
						}
					}
					break;
				case 1:
					Sleep(1000);
					if (loadGameMenu()) {
						while (1) {
							loading();

							if (newGame()) {
								Sleep(1000);

								clrscr();
								map.printBorder();

								if (!constantVar::isMute)PlaySound(TEXT("PUBG.wav"), NULL, SND_ASYNC);

								newInput = true;
								break;
							}
							else if (!crashedMenu()) {
								Sleep(1000);
								TextColor(7);

								clrscr();
								map.printBorder();

								//if (!constantVar::isMute)PlaySound(TEXT("PUBG.wav"), NULL, SND_ASYNC);

								newInput = true;
								break;
							}
						}
					}
					else {
						newInput = true;
						map.printBorder();
					}
					break;
				case 2:
					Sleep(500);

					gameSettings();
					newInput = true;

					map.printBorder();
					break;
				case 3:
					clrscr();
					return;
				}
				break;
			}
		}
	}
}

bool Game::crashedMenu() {
	clrscr();
	map.printMap();
	map.deleteOldPlayer();

	TextColor(12);
	gotoXY(30, 8); cout << "   _____ _____             _____ _    _ ______ _____  _ ";
	gotoXY(30, 9); cout << "  / ____|  __ \\     /\\    / ____| |  | |  ____|  __ \\| |";
	gotoXY(30, 10); cout << " | |    | |__) |   /  \\  | (___ | |__| | |__  | |  | | |";
	gotoXY(30, 11); cout << " | |    |  _  /   / /\\ \\  \\___ \\|  __  |  __| | |  | | |";
	gotoXY(30, 12); cout << " | |____| | \\ \\  / ____ \\ ____) | |  | | |____| |__| |_|";
	gotoXY(30, 13); cout << "  \\_____|_|  \\_\\/_/    \\_\\_____/|_|  |_|______|_____/(_)";

	TextColor(7);
	const char* choice[2] = { "YES", "NO" };
	int curPos = 0, x = 36, y = 27;

	TextColor(7);
	gotoXY(35, 25); cout << "Do you want to continue?" << endl;

	while (1) {
		for (int i = 0; i < 2; i++) {
			if (i == curPos) {
				TextColor(227);
				gotoXY(x, y + i);
				cout << choice[i];
				TextColor(7);
			}
			else {
				gotoXY(x, y + i);
				cout << choice[i];
			}
		}

		switch (inputKey()) {
		case 'w':
		case 'W':
			curPos = (curPos + 1) % 2;
			break;
		case 's':
		case 'S':
			curPos = (curPos + 1) % 2;
			break;
		case 13:
			return !curPos;
		}
	}
}

void Game::togglePauseGame() {
	isPausing = !isPausing;
}

void Game::loading() {
	//if (!constantVar::isMute)PlaySound(TEXT("RaceStart.wav"), NULL, SND_ASYNC);
	map.printMap();
	map.deleteOldPlayer();

	drawTitle();

	TextColor(7);
	gotoXY(30, 25);
	cout << "[";
	for (int i = 0; i <= 50; i++) {
		Sleep(35);
		gotoXY(30 + i, 25);
		cout << "=>";
		gotoXY(55, 26);
		cout << i * 2 << "%";
	}
}

void Game::toggleMute() {
	constantVar::isMute = !constantVar::isMute;
}

void Game::toggleHard() {
	constantVar::isHard = !constantVar::isHard;
}

bool Game::newGame() { 
	if (!isLoaded) {
		map.~Map();
		new(&map) Map();
	}
	isPausing = false;
	map.printMap();
	if (!isLoaded)
		map.initializeNewState();
	isLoaded = false;
	return operatingGame();
}

bool Game::operatingGame(){
	char key;
	const string choice[3] = { "Save Game","Load Game","Quit" };
	int pos = 0;
	while (!map.isEnd()) {
		if (!isPausing) 
			map.randomNextState();
		int x = 125, y = 22;
		if (isPausing) {
			TextColor(15);
			gotoXY(125, 19); 
			cout << "PAUSE MENU" << endl;
			for (int i = 0; i < 3; i++) {
				gotoXY(x, y + i);
				if (i == pos)
					TextColor(11);
				else
					TextColor(15);
				cout << choice[i] << endl;
			}
		}
		if (_kbhit()) {
			key = _getch();
			if (key == 'l')
				saveGameMenu();
			if (key == 't') {
				togglePauseGame();
				loadGameMenu();
				loading();
				clrscr();
				map.redrawMap();
				togglePauseGame();
				isLoaded = false;
			}
			if (key == 'p') {
				togglePauseGame();
				pos = 0; // reset pause menu selection
				if (!isPausing) { // map.redrawMap();
					gotoXY(125, 19); 
					cout << "                  " << endl;
					for (int i = 0; i < 3; i++) {
						gotoXY(x, y + i);
						cout << "                 " << endl;
					}
				}
			}
			if (key == 'a')
				if (!isPausing) 
					map.updatePosPlayer('a');
			if (key == 'w') {
				if (!isPausing) map.updatePosPlayer('w');
				else {
					pos--;
					pos = (pos + 3) % 3;
				}
			}
			if (key == 's') {
				if (!isPausing) map.updatePosPlayer('s');
				else {
					pos++;
					pos %= 3;
				}
			}
			if (key == 'd') {
				if (!isPausing)
				map.updatePosPlayer('d');
			}
			if (isPausing && key == 13) {
				switch (pos) {
				case 0:
					saveGameMenu();
					break;
				case 1:
					loadGameMenu();
					loading();
					clrscr();
					map.redrawMap();
					togglePauseGame();
					isLoaded = false;
					break;
				case 2:
					TextColor(15);					
					return true;
				}
			}
			TextColor(15);
			map.drawPlayer();
			map.drawMap();
		}
		if (map.isWin()) {
			//if (!constantVar::isMute)PlaySound(TEXT("CompleteStage.wav"), NULL, SND_ASYNC);
			if (map.printLevelUp()) {
				clrscr();
				map.nextLevel();
				map.printMap();
				map.deleteOldPlayer();
				map.initializeNewState();
				map.drawPlayer();
			}
			else 
				return true;
		}
	}
	return false;
}

bool Game::continueGame() {
	isPausing = false;
	map.printMap();
	map.initializeNewState();
	return operatingGame();
}

bool Game::loadGameMenu() {
	string filename;
	clrscr();
	vector <string> files = getAllFilename("data");
	if (files.size() == 0) {
		gotoXY(30, 15);
		cout << "No saved file to load !!!";
		Sleep(1000);
		return false;
	}
	int curPos = 0;

	clrscr();
	map.printBorder();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	gotoXY(15, 5); cout << "**      *******      ****     *******" << endl;
	gotoXY(15, 6); cout << "**     **     **    **  **    **     *" << endl;
	gotoXY(15, 7); cout << "**     **     **   ********   **      * **     ** ******** **    ** **    **" << endl;
	gotoXY(15, 8); cout << "****** **     **  **********  **     *  ** * * ** **       ** *  ** **    **" << endl;
	gotoXY(15, 9); cout << "******  *******  **        ** *******   **  *  ** *******  **  * ** **    **" << endl;
	gotoXY(15, 10); cout << "                                        **     ** **       **   *** **    **" << endl;
	gotoXY(15, 11); cout << "                                        **     ** ******** **    ** ********" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	gotoXY(30, 13); cout << "<Press ESC to escape...>";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoXY(30, 15);
	cout << "Choose Filename to load: ";

	for (int i = 0; i < (int)files.size(); ++i) {
		if (i == curPos) {
			gotoXY(26, 16 + i);
			cout << ">> ";
		}
		gotoXY(30, 16 + i);
		cout << files[i] << endl;
	}
	while (true) {
		if (_kbhit())
		{
			char key = _getch();
			if (key == 'w')
			{
				gotoXY(26, 16 + curPos);
				cout << "    " << files[curPos];
				curPos--;
				curPos = (curPos + files.size()) % files.size();
				gotoXY(26, 16 + curPos);
				cout << ">>  " << files[curPos];
			}
			if (key == 's')
			{
				gotoXY(26, 16 + curPos);
				cout << "    " << files[curPos];
				curPos++;
				curPos = (curPos + files.size()) % files.size();
				gotoXY(26, 16 + curPos);
				cout << ">>  " << files[curPos];
			}
			if (key == 13)
			{
				isLoaded = true;
				map.loadGame(files[curPos]);
				clrscr();
				//map.redrawMap();
				return true;
			}
			if (key == 27)
			{
				clrscr();
				//map.redrawMap();
				return false;
			}
		}
		Sleep(200);
	}
}
void Game::saveGameMenu() { // get file of cMap ma
	string filename;
	clrscr();
	map.printBorder();
	map.deleteOldPlayer();

	TextColor(10);
	gotoXY(15, 5); cout << "*******        **** **    ** ******* " << endl;
	gotoXY(15, 6); cout << " **          **  **  **   ** ** " << endl;
	gotoXY(15, 7); cout << "   **      ********   **  ** *******    **     ** ******** **    ** **    **  " << endl;
	gotoXY(15, 8); cout << "     **   **     **    ** ** **         ** * * ** **       ** *  ** **    ** " << endl;
	gotoXY(15, 9); cout << "******   *       **     **** *******    **  *  ** *******  **  * ** **    **  " << endl;
	gotoXY(15, 10); cout << "                                        **     ** **       **   *** **    **   " << endl;
	gotoXY(15, 11); cout << "                                        **     ** ******** **    ** ********  " << endl;
	
	TextColor(11);
	gotoXY(15, 20);
	cout << "<Press ESC to escape>";
	
	gotoXY(15, 15);
	cout << "Input file name to save: ";
	
	TextColor(15);
	char key;
	while ((key = _getch()) != 27) {
		switch (key) {
		case '\b':
			if (filename.size() != 0) {
				filename.pop_back();
				gotoXY(50, 15);
				cout << "                                                 ";
				gotoXY(50, 15);
				cout << filename;
			}
			break;
		case 13:
			map.saveGame(filename);
			break;
		default:
			filename.push_back(key);
			gotoXY(50, 15);
			cout << filename;
		}
		if (key == 13) break;
	}
	clrscr();
	map.redrawMap();
}

void Game::gameOver() {}

vector<string> Game::getAllFilename(const std::string& name) {
	vector<string> v;
	
	string pattern(name);
	pattern.append("\\*");
	
	wstring stemp = wstring(pattern.begin(), pattern.end());
	LPCWSTR sw = stemp.c_str();
	WIN32_FIND_DATA data;
	HANDLE hFind;
	
	if ((hFind = FindFirstFile(sw, &data)) != INVALID_HANDLE_VALUE) {
		do {
			wchar_t* txt = data.cFileName;
			wstring ws(txt);
			string str(ws.begin(), ws.end());
			if (str[0] == '.') continue;
			v.push_back(str);
		} while (FindNextFile(hFind, &data) != 0);
		FindClose(hFind);
	}
	return v;
}

// void Game::menu(bool& isFinish) {}
// void Game::testThread() {}
// void Game::pauseMenu(int cmd) {}
// void saveGame(); // print file of cMap map
// void Game::playGame(bool& is_finish) {}
