#ifndef Lanes_h
#define Lanes_h

#include <vector>

#include "OneLane.h"

using namespace std;


class Lanes {
private:
	vector <OneLane*> subLanes;
public:
	Lanes();
	~Lanes() = default;

	void pushRow(OneLane*);
	bool pushEnemy(int row, Obstacle* obstacle); //  push a new enemy to a row

	vector <OneLane*> listLane();
	vector <Obstacle*> listObstacle(); // return all enemies from all rowsgit ad
	
	int moveToNextState(int t);
};


#endif // cRows