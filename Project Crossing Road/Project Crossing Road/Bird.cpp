#include "Bird.h"
using namespace std;


Bird::Bird() {
	a = new char*[4];
	for (int i = 0; i < 4; ++i)
		a[i] = new char[3];

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 3; ++j)
			a[i][j] = 32;
	}
	
	a[2][0] = (char)220;
	a[2][1] = (char)32;
	a[2][2] = (char)220;
	a[3][0] = (char)32;
	a[3][1] = (char)223;
	a[3][2] = (char)32;
}

Bird::Bird(Position pos) : Obstacle(pos) {
	a = new char* [4];
	for (int i = 0; i < 4; ++i)
		a[i] = new char[3];

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 3; ++j)
			a[i][j] = 32;
	}

	a[2][0] = (char)220;
	a[2][1] = (char)32;
	a[2][2] = (char)220;
	a[3][0] = (char)32;
	a[3][1] = (char)223;
	a[3][2] = (char)32;
}


Bird::~Bird() {
	for (int i = 0; i < 4; i++)
		delete[] a[i];
	delete[] a;
}


char** Bird::shape() { return a; };
void Bird::sound() { PlaySound(TEXT("Bird.wav"), NULL, SND_SYNC); };

int Bird::getWidth() { return 3; }
int Bird::getHeight() { return 4; }
int Bird::getType() { return 0; }


void Bird::test() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			cout << a[i][j];
		}
		cout << endl;
	}
}