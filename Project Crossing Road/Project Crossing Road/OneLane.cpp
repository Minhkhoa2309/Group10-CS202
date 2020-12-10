#include "OneLane.h"

// ========== Temp ========== //
OneLane::OneLane(int speed, bool direction, bool redLight, int currentRow) {}

vector<Obstacle*> OneLane::getObstacle() { return enemy; }
int OneLane::getSpeed() { return 0; }
int OneLane::getCurrentRow() { return 0; }
bool OneLane::getDirection() { return 0; }
bool OneLane::getRedLight() { return 0; }

bool OneLane::pushObstacle(Obstacle* newObstacle) { return false; }
int OneLane::moveToNextState(int t) { return 0; }
void OneLane::redrawState() {}
void OneLane::toggleRedLight() {}
void OneLane::deleteOldObstacle(Position pos, int w, int h) {}
bool OneLane::printNewObstacle(Position pos, char** shape, int w, int h) { return false; }