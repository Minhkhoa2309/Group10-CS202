#ifndef _cgame_h_
#define _cgame_h_

#include"CANIMAL.h"
#include"CPEOPLE.h"
#include"CVEHICLE.h"
#include <iostream>

using namespace std;

class CGAME {
	CTRUCK* axt;
	CCAR* axh;
	CDINAUSOR* akl;
	CBIRD* ac;
	CPEOPLE cn;
public:
	CGAME();
	void drawGame();
	~CGAME(); 
	CPEOPLE getPeople();
	CVEHICLE* getVehicle();
	CANIMAL* getAnimal(); 
	void resetGame(); 
	void exitGame(HANDLE); 
	void startGame(); 
	void loadGame(istream); 
	void saveGame(istream); 
	void pauseGame(HANDLE);
	void resumeGame(HANDLE); 
	void updatePosPeople(char); 
	void updatePosVehicle();
	void updatePosAnimal();
};

#endif