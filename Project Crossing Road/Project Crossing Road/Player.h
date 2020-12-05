#ifndef Player_h
#define Player_h

#define RIGHTMAP 58
#define LEFTMAP 2

#include "ConsoleWindow.h"
#include "Position.h"
#include "Obstacle.h"
#include "Bird.h"
#include "Car.h"
#include "Dinosaur.h"
#include "Truck.h"

#include <cmath>


class Player {
private:
	Position pos;
	bool isDead;
	char** a;  //a[3][5]
	char** emptyPlayer;
	int width = 5, height = 3;
public:
	Player(); // set default position
	Player(Position pos); // set current position when load game

	~Player();

	Position getPos();
	int getX();
	int getY();
	int getWidth();
	int getHeight();

	char** shape();
	char** emptyShape();
	bool checkIsDead();
	bool crash(Position pos, int w, int h);

	void Up();
	void Down();
	void Right();
	void Left();
	void killPlayer(); // set isDead
	void sound();

};
#endif // Player