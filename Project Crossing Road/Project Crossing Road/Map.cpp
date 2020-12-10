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

