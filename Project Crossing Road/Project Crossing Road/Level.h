#ifndef Level_h
#define Level_h

#include <algorithm>
#include "Position.h"
#include "Obstacle.h"	
#include "Bird.h"
#include "Car.h"
#include "Dinosaur.h"
#include "Truck.h"


class Level {
private:
	int level;
	int maxObstacle, minSpeed, maxSpeed, nObstacle;
	int nLane;
	const int maxLevel = 5;
	void initialize();
public:
	Level();
	Level(int level, int nEnemy);

	Obstacle* randNewObstacle(Position pos);
	Obstacle* getNewObstacle(Position pos, int type);
	void decNObstacle(int d);
	
	bool newLevel(int lv);
	bool nextLevel();

	int getLevel();
	int getMaxSpeed();
	int getMinSpeed();
	int getNLane();
};

#endif // cLevel