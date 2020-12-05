#include "Bird.h"
using namespace std;


Bird::Bird() {
	a = new char*[2];
	a[0] = new char[3];
	a[1] = new char[3];
	
	a[0][0] = 220;
	a[0][1] = 32;
	a[0][2] = 220;
	a[1][0] = 32;
	a[1][1] = 223;
	a[1][2] = 32;
}

Bird::Bird(Position pos) : Obstacle(pos) {
	a = new char* [2];
	a[0] = new char[3];
	a[1] = new char[3];

	a[0][0] = 220;
	a[0][1] = 32;
	a[0][2] = 220;
	a[1][0] = 32;
	a[1][1] = 223;
	a[1][2] = 32;
};


Bird::~Bird() {
	for (int i = 0; i < 2; i++)
		delete[] a[i];
	delete[] a;
}


void Bird::test() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout << a[i][j];
		}
		cout << endl;
	}
};


char** Bird::shape() { return a; };
int Bird::getType() { return 0; }
void Bird::sound() { PlaySound(TEXT("boc4.wav"), NULL, SND_ASYNC); };