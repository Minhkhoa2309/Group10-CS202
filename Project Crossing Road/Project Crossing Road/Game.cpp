#include "CGAME.h"


//CGAME::CGAME() {}

//CGAME::CGAME(int level) {}

CGAME::CGAME(const CGAME& b) {
	Player = b.Player;

	numOfTrucks = b.numOfTrucks;
	numOfCars = b.numOfCars;
	numOfDinos = b.numOfDinos;
	numOfBirds = b.numOfBirds;
	
	int i;

	arrTruck = new CTRUCK[numOfTrucks];
	for (i = 0; i < numOfTrucks; ++i) { arrTruck[i] = b.arrTruck[i]; }

	arrCar = new CCAR[numOfCars];
	for (i = 0; i < numOfCars; ++i) { arrCar[i] = b.arrCar[i]; }

	arrDino = new CDINAUSOR[numOfDinos];
	for (i = 0; i < numOfDinos; ++i) { arrDino[i] = b.arrDino[i]; }

	arrBird = new CBIRD[numOfBirds];
	for (i = 0; i < numOfBirds; ++i) { arrBird[i] = b.arrBird[i]; }

	a_isRunning = b.a_isRunning;
	a_curLevel = b.a_curLevel;
}

CGAME::~CGAME() {
	clearGame();
}

//CGAME CGAME::operator=(const CGAME& b) {}


//void CGAME::drawGame() {}


CPEOPLE* CGAME::getPeople() { return Player; }
CVEHICLE* CGAME::getTruck() { return arrTruck; }
CVEHICLE* CGAME::getCar() { return arrCar; }
CANIMAL* CGAME::getDino() { return arrDino; }
CANIMAL* CGAME::getBird() { return arrBird; }

int CGAME::getTruckNum() { return numOfTrucks; }
int CGAME::getCarNum() { return numOfCars; }
int CGAME::getDinoNum() { return numOfDinos; }
int CGAME::getBirdNum() { return numOfBirds; }

bool CGAME::isRunning() { return a_isRunning; }
int CGAME::curLevel() { return a_curLevel; }


void CGAME::pauseGame() { a_isRunning = 0; }
void CGAME::resumeGame() { a_isRunning = 1; }
//void CGAME::startGame() {}

void CGAME::exitGame(thread* a) {
	a->join();
	a_isRunning = 0;
}

// === Constructing === //
void CGAME::resetGame(int level) {
	clearGame();
	a_curLevel = level;
	a_isRunning = 1;

	Player = new CPEOPLE((LEFT + RIGHT) / 2, BOTTOM);
}

void CGAME::clearGame() {
	delete Player;
	delete[] arrTruck;
	delete[] arrCar;
	delete[] arrDino;
	delete[] arrBird;
}

// === Constructing === //
bool CGAME::loadGame(const char* dir) {
	ifstream in(dir);

	if (!in.is_open()) { return 0; }

	string check;
	getline(in, check);
	if (check != CHECK) { 
		in.close(); 
		return 0; 
	}

	in >> a_curLevel;


	return 1;
}

// === Constructing === //
bool CGAME::saveGame(const char* dir) {
	ofstream out(dir);

	if (!out.is_open()) { return 0; }

	out << "CROOSING_ROAD_SAVEFILE\n";
	
	out << a_curLevel << ',';
		//<< Player->x << ',' << Player->y << ',';

	int i;
	for (i = 0; i < numOfTrucks; ++i)
		//out << arrTruck[i].x << ',' << arrTruck[i].y << ',';

	for (i = 0; i < numOfCars; ++i)
		//out << arrCar[i].x << ',' << arrCar[i].y << ',';

	for (i = 0; i < numOfDinos; ++i)
		//out << arrDino[i].x << ',' << arrDino[i].y << ',';

	for (i = 0; i < numOfBirds; ++i)
		//out << arrBird[i].x << ',' << arrBird[i].y << ',';

	out.close();
	return 1;
}


void CGAME::updatePosPeople(char key) {
	if (key == 'w') {
		Player->Up(1);
	}
	else if (key == 's') {
		Player->Down(1);
	}
	else if (key == 'a') {
		Player->Left(1);
	}
	else if (key == 'd') {
		Player->Right(1);
	}
}

void CGAME::updatePosVehicle() {
	int i = 0;

	for (i = 0; i < numOfTrucks; ++i) {
		//arrTruck[i].Move();
	}
	for (i = 0; i < numOfTrucks; ++i) {
		//arrCar[i].Move();
	}
}

void CGAME::updatePosAnimal() {
	int i = 0;

	for (i = 0; i < numOfDinos; ++i) {
		//arrTruck[i].Move();
	}
	for (i = 0; i < numOfBirds; ++i) {
		//arrCar[i].Move();
	}
}