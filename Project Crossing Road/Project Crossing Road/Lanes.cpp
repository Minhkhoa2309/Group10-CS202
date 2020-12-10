#include "Lanes.h"

// ========== Temp ========== //
Lanes::Lanes() {}

bool Lanes::pushEnemy(int row, Obstacle* obstacle) { return false; }
void Lanes::pushRow(OneLane*) {}
vector<Obstacle*> Lanes::listObstacle() { return subLanes[0]->getObstacle(); }
vector<OneLane*> Lanes::listLane() { return subLanes; }
int Lanes::moveToNextState(int t) { return 0; }
void Lanes::redrawState() {}