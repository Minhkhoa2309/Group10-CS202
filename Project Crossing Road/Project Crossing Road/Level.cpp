#include "Level.h"


Level::Level() {
	level = 1;
	nObstacle = 0;
	initialize();
}

Level::Level(int level, int nObstacle) {
	this->level = level;
	this->nObstacle = nObstacle;
	initialize();
}


void Level::initialize() {
	nLane = 7;
	maxObstacle = nLane * 7;
	if (constantVar::isHard) {
		maxSpeed = 5 - level * 2;
		minSpeed = 5 - level * 1;
	}
	else {
		maxSpeed = 50 - level * 2;
		minSpeed = 50 - level * 1;
	}
}


bool Level::newLevel(int lv) {
	if (lv > maxLevel) return false;
	level = lv;
	nObstacle = 0;
	initialize();
	return true;
}

bool Level::nextLevel() {
	if (level >= maxLevel) return false;
	++level;
	nObstacle = 0;
	return true;
}


Obstacle* Level::randNewObstacle(Position pos) {
	if (nObstacle == maxObstacle) return NULL;
	if ((nObstacle < (maxObstacle / 2)) || (rand() % 3)) {
		Obstacle* pObstacle = NULL;
		++nObstacle;

		int type = rand() % 4;
		switch (type) {
		case 0:
			pObstacle = new Bird(pos);
			break;
		case 1:
			pObstacle = new Car(pos);
			break;
		case 2:
			pObstacle = new Dinosaur(pos);
			break;
		default:
			pObstacle = new Truck(pos);
			break;
		}

		return pObstacle;
	}
	return NULL;
}


Obstacle* Level::getNewObstacle(Position pos, int type) {
	Obstacle* pObstacle = NULL;
	++nObstacle;

	switch (type) {
	case 0:
		pObstacle = new Bird(pos);
		break;
	case 1:
		pObstacle = new Car(pos);
		break;
	case 2:
		pObstacle = new Dinosaur(pos);
		break;
	default:
		pObstacle = new Truck(pos);
		break;
	}

	return pObstacle;
}

void Level::decNObstacle(int d) { nObstacle -= d; }

int Level::getLevel() { return level; }
int Level::getMaxSpeed() { return maxSpeed; }
int Level::getMinSpeed() { return minSpeed; }
int Level::getNLane() { return nLane; };