#ifndef OneLane_h
#define OneLane_h

#define RIGHTMAP 58
#define LEFTMAP 2

#include <vector>
#include "Obstacle.h"

using namespace std;


class OneLane {
private:
	vector <Obstacle*> enemy;
	bool direction; //0: to the left, 1: to the right
	bool redLight = false;
	int speed;
	int currentRow;
public:
	OneLane() = default;
	OneLane(int speed, bool direction, bool redLight, int currentRow);
	~OneLane() = default;

	int moveToNextState(int t); // if % speed = 0, move all enemy left or right base on direction && redLight

	bool pushObstacle(Obstacle* newObstacle); // push a new new enemy, if !position => set base on direction
	void deleteOldObstacle(Position pos, int w, int h);
	
	bool printNewObstacle(Position pos, char** shape, int w, int h);

	vector<Obstacle*> getObstacle();
	int getSpeed();
	int getCurrentRow();
	bool getDirection();
	bool getRedLight();
	
	void toggleRedLight();
};


#endif // OneLane