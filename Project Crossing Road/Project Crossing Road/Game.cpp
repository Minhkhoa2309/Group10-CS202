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
			color = rand() % 7 + 9;
			TextColor(color);
			drawTitle();

			for (int i = 0; i < 3; ++i) {
				gotoXY(x, y + i);

				if (i == userPos) { TextColor(11); }
				else { TextColor(15); }

				cout << setting[i] << "\t" << current[i];
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

				int color = rand() % 7 + 9;
				TextColor(color);
				
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
	
	map.bombEffect();

	gotoXY(15, 5); cout << "   _____ _____             _____ _    _ ______ _____  _ ";
	gotoXY(15, 6); cout << "  / ____|  __ \\     /\\    / ____| |  | |  ____|  __ \\| |";
	gotoXY(15, 7); cout << " | |    | |__) |   /  \\  | (___ | |__| | |__  | |  | | |";
	gotoXY(15, 8); cout << " | |    |  _  /   / /\\ \\  \\___ \\|  __  |  __| | |  | | |";
	gotoXY(15, 9); cout << " | |____| | \\ \\  / ____ \\ ____) | |  | | |____| |__| |_|";
	gotoXY(15, 10); cout << "  \\_____|_|  \\_\\/_/    \\_\\_____/|_|  |_|______|_____/(_)";

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