#ifndef cLevel_h
#define cLevel_h

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
	int maxEnemy, minSpeed, maxSpeed, nEnemy;
	int nLane;
	const int maxLevel = 5;
	void initialize();
public:
	Level();
	Level(int level, int nEnemy);

	//  ~cLevel();
	
	int getLevel();
	bool newLevel(int lv);
	bool nextLevel();
	int getMaxSpeed();
	int getMinSpeed();
	Obstacle* randNewObstacle(Position pos);
	Obstacle* getNewObstacle(Position pos, int type);
	void decNEnemy(int d);
};

#endif // cLevel