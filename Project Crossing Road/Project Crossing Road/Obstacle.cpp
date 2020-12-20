#include "Obstacle.h"


Obstacle::Obstacle()
{
	outMap = false;
}

Obstacle::Obstacle(Position pos) 
{
	point = pos;
	outMap = false;
}

Position Obstacle::getPos() {
	return point;
}

int Obstacle::getX() {
	return point.getX();
}

int Obstacle::getY() {
	return point.getY();
}

bool Obstacle::isOutOfMap() {
	return outMap;
}

void Obstacle::goOutMap() {
	outMap = true;
}

int Obstacle::getWidth() {
	return 5;
}

int Obstacle::getHeight() {
	return 2;
}

void Obstacle::updatePosition(int dx, int dy) {
	point.setPos(point.getX() + dx, point.getY() + dy);
}