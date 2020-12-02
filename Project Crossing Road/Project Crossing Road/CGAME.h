#ifndef _cgame_h_
#define _cgame_h_

#include "CVEHICLE.h"
#include "CANIMAL.h"
#include "CPEOPLE.h"
#include "CDINAUSOR.h"
#include "CBIRD.h"
#include "CCAR.h"
#include "CTRUCK.h"
#include <iostream>
#include <fstream>
#include <string>
#include <thread>

using namespace std;

#define CHECK "CROSSING_ROAD_SAVEFILE"

class CGAME {
public:
	static const int MAX_LEVEL;

	static const int TOP;
	static const int BOTTOM;
	static const int LEFT;
	static const int RIGHT;
private:
	CPEOPLE* Player;
	CTRUCK* arrTruck;
	int numOfTrucks;
	CCAR* arrCar;
	int numOfCars;
	CDINAUSOR* arrDino;
	int numOfDinos;
	CBIRD* arrBird;
	int numOfBirds;
	
	bool a_isRunning;
	int a_curLevel;

	friend class CPEOPLE;
	friend class CANIMAL;
	friend class CVEHICLE;
public:
	CGAME();
	CGAME(int);
	CGAME(const CGAME&);
	~CGAME();

	CGAME operator=(const CGAME&);

	void drawGame(); 

	// character pointer
	CPEOPLE* getPeople();
	// obstacle array
	CVEHICLE* getTruck();
	CVEHICLE* getCar();
	CANIMAL* getDino();
	CANIMAL* getBird();
	// num of obstacle
	int getTruckNum();
	int getCarNum();
	int getDinoNum();
	int getBirdNum();
	// game properties
	bool isRunning();
	int curLevel();

	void pauseGame();
	void resumeGame();
	void startGame();
	void exitGame(thread*);
	void resetGame(int);
	void clearGame();
	bool loadGame(const char*); 
	bool saveGame(const char*); 

	void updatePosPeople(char); 
	void updatePosVehicle();
	void updatePosAnimal();
};

#endif
