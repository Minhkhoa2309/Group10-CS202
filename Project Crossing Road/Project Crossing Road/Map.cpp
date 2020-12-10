#include "Map.h"

void Map::printBorder() {
	clrscr();
	gotoXY(0, 0);
	for (int i = 0; i < height; i++) {
		cout << "    ";
		for (int j = 0; j < width; j++)
			cout << map[i][j];
		cout << endl;
	}
}

void Map::printCongrats() {
	clrscr();
	printMap();
	deleteOldPlayer();
	//if (!constantVar::isMute)PlaySound(TEXT("CompleteStage.wav"), NULL, SND_ASYNC);
	gotoXY(23, 15); cout << "########     ##     ###    ##     ##       #######      ##     ##     ##  ##" << endl;
	gotoXY(23, 16); cout << "########     ##     ####   ##     ##      ########      ##     ##     ##  ##" << endl;
	gotoXY(23, 17); cout << "##           ##     ## ##  ##     ##     ###            ##     ##     ##  ##" << endl;
	gotoXY(23, 18); cout << "######       ##     ##  ## ##     ##      #######       #########     ##  ##" << endl;
	gotoXY(23, 19); cout << "##           ##     ##   ####     ##            ###     ##     ##     ##  ##" << endl;
	gotoXY(23, 20); cout << "##           ##     ##    ###     ##      ########      ##     ##	 	    " << endl;
	gotoXY(23, 21); cout << "##           ##     ##    ###     ##      #######       ##     ##     ##  ##" << endl;
	gotoXY(50, 23); cout << "YOU HAVE WON THE GAME!" << endl;
	gotoXY(40, 25); cout << "Exit ?	" << endl;
	const char* choice[2] = { "<YES>", "<OF COURSE>" };
	int pos = 0, x = 36, y = 26;
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
			return;
		}
	}
}

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
		//if (!constantVar::isMute)PlaySound(TEXT("CompleteStage.wav"), NULL, SND_ASYNC);
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