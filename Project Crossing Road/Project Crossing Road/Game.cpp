#include "Game.h"


//CGAME::CGAME() {}

//CGAME::CGAME(int level) {}

//CGAME::CGAME(const CGAME& b) {
//	Player = b.Player;
//
//	numOfTrucks = b.numOfTrucks;
//	numOfCars = b.numOfCars;
//	numOfDinos = b.numOfDinos;
//	numOfBirds = b.numOfBirds;
//	
//	int i;
//
//	arrTruck = new CTRUCK[numOfTrucks];
//	for (i = 0; i < numOfTrucks; ++i) { arrTruck[i] = b.arrTruck[i]; }
//
//	arrCar = new CCAR[numOfCars];
//	for (i = 0; i < numOfCars; ++i) { arrCar[i] = b.arrCar[i]; }
//
//	arrDino = new CDINAUSOR[numOfDinos];
//	for (i = 0; i < numOfDinos; ++i) { arrDino[i] = b.arrDino[i]; }
//
//	arrBird = new CBIRD[numOfBirds];
//	for (i = 0; i < numOfBirds; ++i) { arrBird[i] = b.arrBird[i]; }
//
//	a_isRunning = b.a_isRunning;
//	a_curLevel = b.a_curLevel;
//}
//
//CGAME::~CGAME() {
//	clearGame();
//}
//
////CGAME CGAME::operator=(const CGAME& b) {}
//
//
////void CGAME::drawGame() {}
//
//
//CPEOPLE* CGAME::getPeople() { return Player; }
//CVEHICLE* CGAME::getTruck() { return arrTruck; }
//CVEHICLE* CGAME::getCar() { return arrCar; }
//CANIMAL* CGAME::getDino() { return arrDino; }
//CANIMAL* CGAME::getBird() { return arrBird; }
//
//int CGAME::getTruckNum() { return numOfTrucks; }
//int CGAME::getCarNum() { return numOfCars; }
//int CGAME::getDinoNum() { return numOfDinos; }
//int CGAME::getBirdNum() { return numOfBirds; }
//
//bool CGAME::isRunning() { return a_isRunning; }
//int CGAME::curLevel() { return a_curLevel; }
//
//
//void CGAME::pauseGame() { a_isRunning = 0; }
//void CGAME::resumeGame() { a_isRunning = 1; }
////void CGAME::startGame() {}
//
//void CGAME::exitGame(thread* a) {
//	a->join();
//	a_isRunning = 0;
//}
//
//// === Constructing === //
//void CGAME::resetGame(int level) {
//	clearGame();
//	a_curLevel = level;
//	a_isRunning = 1;
//
//	Player = new CPEOPLE((LEFT + RIGHT) / 2, BOTTOM);
//}
//
//void CGAME::clearGame() {
//	delete Player;
//	delete[] arrTruck;
//	delete[] arrCar;
//	delete[] arrDino;
//	delete[] arrBird;
//}
//
//// === Constructing === //
//bool CGAME::loadGame(const char* dir) {
//	ifstream in(dir);
//
//	if (!in.is_open()) { return 0; }
//
//	string check;
//	getline(in, check);
//	if (check != CHECK) { 
//		in.close(); 
//		return 0; 
//	}
//
//	in >> a_curLevel;
//
//
//	return 1;
//}
//
//// === Constructing === //
//bool CGAME::saveGame(const char* dir) {
//	ofstream out(dir);
//
//	if (!out.is_open()) { return 0; }
//
//	out << "CROOSING_ROAD_SAVEFILE\n";
//	
//	out << a_curLevel << ',';
//		//<< Player->x << ',' << Player->y << ',';
//
//	int i;
//	for (i = 0; i < numOfTrucks; ++i)
//		//out << arrTruck[i].x << ',' << arrTruck[i].y << ',';
//
//	for (i = 0; i < numOfCars; ++i)
//		//out << arrCar[i].x << ',' << arrCar[i].y << ',';
//
//	for (i = 0; i < numOfDinos; ++i)
//		//out << arrDino[i].x << ',' << arrDino[i].y << ',';
//
//	for (i = 0; i < numOfBirds; ++i)
//		//out << arrBird[i].x << ',' << arrBird[i].y << ',';
//
//	out.close();
//	return 1;
//}
//
//
//void CGAME::updatePosPeople(char key) {
//	if (key == 'w') {
//		Player->Up(1);
//	}
//	else if (key == 's') {
//		Player->Down(1);
//	}
//	else if (key == 'a') {
//		Player->Left(1);
//	}
//	else if (key == 'd') {
//		Player->Right(1);
//	}
//}
//
//void CGAME::updatePosVehicle() {
//	int i = 0;
//
//	for (i = 0; i < numOfTrucks; ++i) {
//		//arrTruck[i].Move();
//	}
//	for (i = 0; i < numOfTrucks; ++i) {
//		//arrCar[i].Move();
//	}
//}
//
//void CGAME::updatePosAnimal() {
//	int i = 0;
//
//	for (i = 0; i < numOfDinos; ++i) {
//		//arrTruck[i].Move();
//	}
//	for (i = 0; i < numOfBirds; ++i) {
//		//arrCar[i].Move();
//	}
//}

void Game::loading() {
	//if (!constantVar::isMute)PlaySound(TEXT("RaceStart.wav"), NULL, SND_ASYNC);
	map.printMap();
	map.deleteOldPlayer();
	drawTitle();
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

void Game::gameSettings(){}
void Game::menu(bool& isFinish) {}
bool Game::loadGameMenu() {
	return false;
} // get file of cMap map
void Game::saveGameMenu() {} //void saveGame(); // print file of cMap map
void Game::pauseMenu(int cmd) {}
void Game::togglePauseGame() {}// toggle status of isPausing
void Game::gameOver() {}
void Game::playGame(bool& is_finish) {}
void Game::testThread() {}
void Game::menu() {}
vector<string> getAllFilename(const std::string& name) {
	vector<string> x = {};
	return x;
}
