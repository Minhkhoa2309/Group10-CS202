#include "Lanes.h"

Lanes::Lanes() {
	subLanes.reserve(100);
}

bool Lanes::pushEnemy(int row, Obstacle* obstacle) { 
	if (row >= (int)subLanes.size())  return false;
	return subLanes[row]->pushObstacle(obstacle);
}
void Lanes::pushRow(OneLane* lane) {
	subLanes.push_back(lane);
}
vector<Obstacle*> Lanes::listObstacle() {
	vector<Obstacle*> listObstacle, tmp;
	for (int i = 0; (unsigned)i < subLanes.size(); i++) {
		tmp = subLanes[i]->getObstacle();
		listObstacle.insert(listObstacle.end(), tmp.begin(), tmp.end());
	}
	return listObstacle;
}
vector<OneLane*> Lanes::listLane() { return subLanes; }
int Lanes::moveToNextState(int t) {
	int nDelete = 0;
	for (int i = 0; i < (int)subLanes.size(); ++i) {
		nDelete += subLanes[i]->moveToNextState(t);
	}
	return nDelete;
}