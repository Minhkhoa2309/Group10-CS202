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
	
	bool pushEnemy(int row, Obstacle* obstacle); //  push a new enemy to a row
	void pushRow(OneLane*);
	vector <Obstacle*> listObstacle(); // return all enemies from all rowsgit ad
	vector <OneLane*> listLane();
	int moveToNextState(int t);
	void redrawState();
};


#endif // cRows