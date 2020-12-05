#ifndef Obstacle_h
#define Obstacle_h

#include <iostream>
#include <Windows.h>
#include <mmsystem.h>

#include "ConsoleWindow.h"
#include "Position.h"

using namespace std;


class Obstacle {

private:
	Position point;
	bool outMap;

public:
	Obstacle();
	Obstacle(Position st); // create new enemy with starting position
	
	virtual ~Obstacle() = default;

	Position getPos();
	int getX();
	int getY();
	virtual int getWidth();
	int getHeight();
	virtual int getType() = 0;
	virtual char** shape() = 0; // return the shape of enemy to draw

	void updatePosition(int dx, int dy);
	virtual void sound() = 0;
	bool isOutOfMap();
	void goOutMap();
};


#endif // Obstacle