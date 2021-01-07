#include "OneLane.h"
#include <Windows.h>
OneLane::OneLane(int speed, bool direction, bool redLight, int currentRow) {
	this->speed = speed;
	this->direction = direction;
	this->redLight = redLight;
	this->currentRow = currentRow;
	enemy.reserve(100);
}

vector<Obstacle*> OneLane::getObstacle() { return enemy; }
int OneLane::getSpeed() { return speed; }
int OneLane::getCurrentRow() { return currentRow; }
bool OneLane::getDirection() { return direction; }
bool OneLane::getRedLight() { return redLight; }

bool OneLane::pushObstacle(Obstacle* newObstacle) {
	if (!direction) {
		newObstacle->updatePosition(0, RIGHTMAP - newObstacle->getY());
	}
	if (newObstacle->getY() > RIGHTMAP || newObstacle->getY() <= 1 || (enemy.size() && abs(enemy.back()->getY() - newObstacle->getY()) <= 8)) {
		return false;
	}
	enemy.push_back(newObstacle);
	printNewObstacle(newObstacle->getPos(), newObstacle->shape(), newObstacle->getWidth(), newObstacle->getHeight());
	return true;
}
int OneLane::moveToNextState(int t) { 
	int nDelete = 0;
	if ((redLight && (rand() % 8 == 0)) || (!redLight && (rand() % 15 == 0)) || (t == 0)) {
		toggleRedLight();
	}
	if (redLight) {
		TextColor(12);
	}
	else {
		TextColor(10);
	}
	if (direction)
	{
		gotoXY(RIGHTMAP + 60, currentRow + 2);
	}
	else
	{
		gotoXY(LEFTMAP - 1, currentRow + 2);
	}
	cout << (char)254;
	TextColor(7);
	// if (redLight) return nDelete;
	vector <Obstacle*> newObstacle;
	newObstacle.reserve(100);
	for (int i = 0; i < (int)enemy.size(); ++i) {
		Obstacle* curObstacle = enemy[i];
		if (!redLight) {
			int dy = -1;
			if (direction) dy = 1;
			deleteOldObstacle(curObstacle->getPos(), curObstacle->getWidth(), curObstacle->getHeight());
			curObstacle->updatePosition(0, dy);
		}
		// Print Enemy
		Sleep(1);
		bool canPrint = printNewObstacle(curObstacle->getPos(), curObstacle->shape(), curObstacle->getWidth(), curObstacle->getHeight());
		if (!canPrint) {
			curObstacle->goOutMap();
			++nDelete;
		}
		if (curObstacle->isOutOfMap()) {
			delete curObstacle;
		}
		else {
			newObstacle.push_back(curObstacle);
		}
	}
	enemy = newObstacle;
	return nDelete;
}
void OneLane::toggleRedLight() {
	redLight = !redLight;
}
void OneLane::deleteOldObstacle(Position pos, int w, int h) {
	int X = pos.getX();
	int Y = pos.getY();
	if (Y == LEFTMAP) return;
	if (Y > RIGHTMAP) return;
	for (int i = 2; i < h; ++i) {
		for (int j = max(1, Y); j <= min(RIGHTMAP, Y + w - 1); ++j) {
			gotoXY(Y + j, X + i);
			cout << ' ';
		}
	}
}
bool OneLane::printNewObstacle(Position pos, char** shape, int w, int h) { 
	int X = pos.getX();
	int Y = pos.getY();
	
	if (Y == LEFTMAP || Y > RIGHTMAP) return 0;

	for (int i = 2; i < h; ++i) {
		for (int j = max(1, Y); j <= min(RIGHTMAP, Y + w - 1); ++j) {
			gotoXY(Y + j, X + i);
			cout << shape[i][j - max(1, Y)];
		}
	}
	return 1;
}

