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
	char** a;  //a[3][5]
	char** emptyPlayer;
	int width = 3, height = 4;
	bool isDead;
public:
	Player(); // set default position
	Player(Position pos); // set current position when load game
	~Player();

	int getX();
	int getY();
	Position getPos();
	int getWidth();
	int getHeight();

	char** shape();
	char** emptyShape();
	bool IsDead();
	bool crash(Position pos, int w, int h);

	void Up();
	void Down();
	void Left();
	void Right();
	void gotHit(); // set isDead
	void sound();

	void drawPlayer();
};
#endif // Player