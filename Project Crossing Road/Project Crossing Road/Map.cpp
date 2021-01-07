#include "Map.h"

void Map::printBorder() {
	clrscr();
	gotoXY(0, 0);
	for (int i = 0; i <= height + 1; i++) {
		cout << "  ";
		for (int j = 0; j <= width + 1; j++)
			cout << map[i][j];
		cout << endl;
	}
}

void Map::printCongrats() {
	clrscr();
	printMap();
	deleteOldPlayer();
	if (!constantVar::isMute)PlaySound(TEXT("CompleteSound.wav"), NULL, SND_ASYNC);
	gotoXY(23, 15); cout << "########     ##     ###    ##     ##       #######      ##     ##     ##  ##" << endl;
	gotoXY(23, 16); cout << "########     ##     ####   ##     ##      ########      ##     ##     ##  ##" << endl;
	gotoXY(23, 17); cout << "##           ##     ## ##  ##     ##     ###            ##     ##     ##  ##" << endl;
	gotoXY(23, 18); cout << "######       ##     ##  ## ##     ##      #######       #########     ##  ##" << endl;
	gotoXY(23, 19); cout << "##           ##     ##   ####     ##            ###     ##     ##     ##  ##" << endl;
	gotoXY(23, 20); cout << "##           ##     ##    ###     ##      ########      ##     ##	 	    " << endl;
	gotoXY(23, 21); cout << "##           ##     ##    ###     ##      #######       ##     ##     ##  ##" << endl;
	gotoXY(50, 23); cout << "YOU HAVE WON THE GAME!" << endl;
	const char* back = "<BACK TO MENU>";
	while (inputKey() != 13) {
		TextColor(7);
		TextColor(227);
		gotoXY(55, 24);
		cout << back;
		TextColor(7);
	}
}

Map::Map() : width(115), height(36) {
	for (int i = 0; i <= width; ++i) {
		map[0][i] = '-';
		map[height + 1][i] = '-';
	}
	map[0][width + 1] = map[height + 1][width + 1] = ' ';

	for (int i = 1; i <= height; ++i) {
		map[i][0] = map[i][width] = '|';
		map[i][width + 1] = ' ';

		for (int j = 1; j < width; ++j) {
			map[i][j] = ' ';
		}
	}
}

bool Map::printLevelUp() {
	if (level.getLevel() == 5) {
		printCongrats();
		return false;
	}
	else {
		clrscr();
		printMap();
		deleteOldPlayer();
		gotoXY(15, 15); cout << " #####    #######       #######      #######    #######     ######     #######      ###   ###" << endl;
		gotoXY(15, 16); cout << "##    #   ##    ##     ##     ##    ###        ###          ##         ##    ##     ###   ###" << endl;
		gotoXY(15, 17); cout << "##        #### ##     ##       ##     ####       ####       ######     ##     ##    ###   ###" << endl;
		gotoXY(15, 18); cout << "##    #   ##   ##      ##     ##         ###        ###     ##         ##    ##              " << endl;
		gotoXY(15, 19); cout << " #####    ##    ##      #######      ######     ######      ######     #######      ###   ###" << endl;
		gotoXY(35, 21); cout << "Continue ?" << endl;
		const char* choice[2] = { "<YES>", "<NO>" };
		int pos = 0, x = 36, y = 22;
		TextColor(7);
		/*TextColor(227);
		gotoXY(x, y);
		cout << choice[0];
		TextColor(7);

		TextColor(227);
		gotoXY(x+10, y);
		cout << choice[1];
		TextColor(7);*/

		while (1) {
			TextColor(7);
			for (int i = 0; i < 2; i++) {
				if (i == pos) {
					TextColor(227);
					gotoXY(x, y + i);
					cout << choice[i];
					TextColor(7);
				}
				else {
					gotoXY(x, y + i);
					cout << choice[i];
				}
			}

			switch (inputKey()) {
			case 'w':
				pos--;
				pos = abs(pos);
				pos %= 2;
				break;
			case 's':
				pos++;
				pos %= 2;
				break;
			case 13:
				return !pos;
			}
		}
	}
}

bool Map::isEnd() {
	return player.IsDead();
}

bool Map::isWin() {
	if (player.getX() == 1) {
		if (!constantVar::isMute)PlaySound(TEXT("CompleteSound.wav"), NULL, SND_ASYNC);
		return true;
	}
	return false;
}

void Map::nextLevel() {
	level.nextLevel();
}

void Map::printInt(int x, ofstream& outfile) {
	outfile.write((char*)&x, sizeof(int));
}

int Map::readInt(ifstream& infile) {
	int x;
	infile.read((char*)&x, sizeof(int));
	return x;
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
		if (player.crash(obstacleList[i]->getPos(), obstacleList[i]->getWidth(), obstacleList[i]->getHeight())) {
			if (!constantVar::isMute) { obstacleList[i]->sound(); }
			player.gotHit();
			deleteOldPlayer();
			drawPlayer();
			Sleep(300);
			clrscr();
			printMap();
			deleteOldPlayer();
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

void Map::drawPlayer() {
	int status = draw(player.getPos(), player.shape(), player.getWidth(), player.getHeight());
	/*if (status == -1) {
		player.killPlayer(); // cho nay nhin co ve la k dung
	}*/
}

void Map::randomNextState() {
	srand(time(NULL));

	Obstacle* newEnemy;
	Position pos;
	int numOfLanes = level.getNLane();

	int tryCount = 10000;
	while (tryCount--) {
		int rRow = rand() % numOfLanes;

		pos = Position((rRow * 4) + 5, 3);
		// pos = Position((rRow * 4) + 5, 2);
		newEnemy = level.randNewObstacle(pos);
		
		if (!newEnemy) break;
		if (!rowsData.pushEnemy(rRow, newEnemy)) {
			level.decNObstacle(1);
			delete newEnemy;
		}
	}
	++t;
	int tmp = rowsData.moveToNextState(t);
	level.decNObstacle(tmp);
	drawMap();
}
void Map::initializeNewState() {
	player.~Player();
	new(&player) Player();
	rowsData.~Lanes();
	new(&rowsData) Lanes();

	int numOfLanes = level.getNLane();
	for (int i = 0; i < numOfLanes; ++i) {
		int speed = rand() % (level.getMinSpeed() - level.getMaxSpeed() + 1) + level.getMaxSpeed();
		bool direction = rand() % 2;
		//bool redLight = rand() % 2;
		//rowsData.pushRow(new OneLane(speed, direction, redLight, (i * 4) + 5));
		rowsData.pushRow(new OneLane(speed, direction, 1, (i * 4) + 5));
	}

	Obstacle* newEnemy;
	Position pos;
	int tryCount = 10000;
	int* padding = new int[numOfLanes] { 0 };
	while (tryCount--) {
		int rRow = rand() % numOfLanes;
		padding[rRow] += (rand() % 20) + 9;
		// padding[rRow] += rand() % 10;
		
		pos = Position((rRow * 4) + 5, padding[rRow]);
		newEnemy = level.randNewObstacle(pos);
		
		if (!newEnemy) break;
		if (!rowsData.pushEnemy(rRow, newEnemy)) {
			level.decNObstacle(1);
			delete newEnemy;
		}
	}
	Sleep(200);
	rowsData.moveToNextState(0);
}
void Map::updatePosPlayer(char moving) {
	deleteOldPlayer();
	if (moving == 'a' || moving == 'A') player.Left();
	else if (moving == 'w' || moving == 'W') player.Up();
	else if (moving == 'd' || moving == 'D') player.Right();
	else if (moving == 's' || moving == 'S') player.Down();
	else return;
}

bool Map::saveGame(string file) {
	ofstream outfile("./saved/" + file + ".bin", ios::out | ios::binary);
	if (!outfile.is_open()) {
		return false;
	}

	printInt(constantVar::isHard, outfile);
	printInt(constantVar::isMute, outfile);
	printInt(level.getLevel(), outfile);
	printInt(player.getX(), outfile);
	printInt(player.getY(), outfile);

	vector <OneLane*> rows(rowsData.listLane());
	printInt((int)rows.size(), outfile);
	for (int i = 0; i < rows.size(); ++i) {
		printInt(rows[i]->getCurrentRow(), outfile);
		printInt((int)rows[i]->getDirection(), outfile);
		printInt(rows[i]->getSpeed(), outfile);
		printInt((int)rows[i]->getRedLight(), outfile);

		vector <Obstacle*> enemy(rows[i]->getObstacle());
		printInt((int)enemy.size(), outfile);

		for (int j = 0; j < (int)enemy.size(); ++j) {
			printInt(enemy[j]->getX(), outfile);
			printInt(enemy[j]->getY(), outfile);
			printInt(enemy[j]->getType(), outfile);
		}
	}
	outfile.close();

	return true;
}
bool Map::loadGame(string file) {
	ifstream infile("./saved/" + file, ios::in | ios::binary);
	if (!infile.is_open()) {
		return false;
	}
	
	constantVar::isHard = readInt(infile);
	constantVar::isMute = readInt(infile);
	int lv = readInt(infile);
	level.~Level();
	new(&level) Level(lv, 0);
	int playerX, playerY;
	playerX = readInt(infile);
	playerY = readInt(infile);
	player.~Player();
	new(&player) Player(Position(playerX, playerY));

	int nEnemy = 0;

	rowsData.~Lanes();
	new(&rowsData) Lanes();

	int numOfLanes = readInt(infile);
	for (int i = 0; i < numOfLanes; ++i) {
		int currentRow, direction, speed, redLight;
		currentRow = readInt(infile);
		direction = readInt(infile);
		speed = readInt(infile);
		redLight = readInt(infile);

		rowsData.pushRow(new OneLane(speed, direction, redLight, currentRow));

		int enemySize = readInt(infile);
		nEnemy += enemySize;

		for (int j = 0; j < enemySize; ++j) {
			int eX, eY, eType;
			eX = readInt(infile);
			eY = readInt(infile);
			eType = readInt(infile);
			rowsData.pushEnemy(i, level.getNewObstacle(Position(eX, eY), eType));
		}
	}
	infile.close();
	return true;
}


