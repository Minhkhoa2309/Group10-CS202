#include "Map.h"


Map::Map() : width(115), height(36) {
	for (int i = 0; i <= width; ++i)
		map[0][i] = map[height - 1][i] = '-';
	map[0][width + 1] = map[height + 1][width + 1] = ' ';
	
	for (int i = 1; i <= height; ++i) {
		map[i][0] = map[i][width] = '|';
		map[i][width + 1] = ' ';
		
		for (int j = 1; j < width; ++j) {
			map[i][j] = ' ';
		}
	}
}

void Map::resetMap() {
	for (int i = 0; i <= width + 1; i++)
		map[0][i] = map[height + 1][i] = '-';

	for (int i = 1; i <= height; ++i) {
		map[i][0] = map[i][width + 1] = '|';
		
		for (int j = 1; j <= width; ++j) {
			map[i][j] = ' ';
		}
	}
}

void Map::printMap() {

	clrscr();

	gotoXY(0, 0);
	for (int i = 0; i <= height + 1; ++i) {
		cout << "  ";
		for (int j = 0; j <= width + 1; ++j) {
			cout << map[i][j];
		}
		cout << endl;
	}
	
	gotoXY(125, 1); cout << "<Crossing Road Game>";
	
	gotoXY(125, 3); cout << "LV. " << level.getLevel() << endl;
	gotoXY(125, 5); cout << "CONTROLS:" << endl;
	gotoXY(127, 6); cout << "[ W ]: UP" << endl;
	gotoXY(127, 7); cout << "[ S ]: DOWN" << endl;
	gotoXY(127, 8); cout << "[ A ]: LEFT" << endl;
	gotoXY(127, 9); cout << "[ D ]: RIGHT" << endl;
	gotoXY(125, 11); cout << "COMMANDS:" << endl;
	gotoXY(127, 12); cout << "[ L ]: Save game" << endl;
	gotoXY(127, 13); cout << "[ T ]: Load game" << endl;
	gotoXY(127, 14); cout << "[ P ]: Pause game/Menu" << endl;

	drawPlayer();
}

void Map::drawMap() {
	vector <Obstacle*> obstacleList = rowsData.listObstacle();
	
	for (int i = 0; i < obstacleList.size(); ++i) {
		if (player.crash(obstacleList[i]->getPos(), obstacleList[i]->getWidth() - 3, obstacleList[i]->getHeight())) {
			if (!constantVar::isMute) { obstacleList[i]->sound(); }
			player.gotHit();
			deleteOldPlayer();
			drawPlayer();
			Sleep(300);
			clrscr();
			printMap();
			deleteOldPlayer();
			bombEffect();
			return;
		}
	}
}

void Map::redrawMap() {
	printMap();
	int tmp = rowsData.moveToNextState(t);
	level.decNObstacle(tmp);
	drawMap();
}

int Map::draw(Position pos, char** shape, int w, int h) {
	int X = pos.getX();
	int Y = pos.getY();

	if (Y + w <= 0) return 0;
	if (Y > width) return 0;

	for (int i = 0; i < h; ++i) {
		for (int j = max(1, Y); j <= min(width, Y + w - 1); ++j) {
			gotoXY(Y + j, X + i);
			cout << shape[i][j - max(1, Y)];
		}
	}
	return 1;
}

void Map::deleteOldPlayer() {
	draw(player.getPos(), player.emptyShape(), player.getWidth(), player.getHeight());
}

// ========== Temp ========== //
void Map::drawPlayer() {}
void Map::drawEnemies(Obstacle* obstacle) {}
void Map::randomNextState() {}
void Map::initializeNewState() {}
void Map::updatePosPlayer(char moving) {}
void Map::bombEffect() {}
void Map::saveGame(string file) {}
bool Map::loadGame(string file) { return false; }
void Map::printBorder() {}
void Map::printCongrats() {}
bool Map::printLevelUp() { return false; }
bool Map::isEnd() { return true; }
bool Map::isWin() { return false; }
void Map::nextLevel() {}
void Map::printInt(int x, ofstream& outline) {}
int Map::readInt(ifstream& infile) { return -1; }