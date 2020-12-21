#include "Dinosaur.h"
using namespace std;


Dinosaur::Dinosaur() {
	a = new char* [4];
	for (int i = 0; i < 4; i++) {
		a[i] = new char[3];
	}

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 3; ++j)
			a[i][j] = 32;
	}
	
	a[2][0] = (char)32;
	a[2][1] = (char)32;
	a[2][2] = (char)220;
	a[3][0] = (char)220;
	a[3][1] = (char)219;
	a[3][2] = (char)223;
}

Dinosaur::Dinosaur(Position pos) : Obstacle(pos) {
	a = new char* [4];
	for (int i = 0; i < 4; i++) {
		a[i] = new char[3];
	}

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 3; ++j)
			a[i][j] = 32;
	}

	a[2][0] = (char)32;
	a[2][1] = (char)32;
	a[2][2] = (char)220;
	a[3][0] = (char)220;
	a[3][1] = (char)219;
	a[3][2] = (char)223;
};


Dinosaur::~Dinosaur() {
	for (int i = 0; i < 4; i++)
		delete[] a[i];
	delete[] a;
}


char** Dinosaur::shape() { return a; };
void Dinosaur::sound() { PlaySound(TEXT("Dinosaur.wav"), NULL, SND_SYNC); };

int Dinosaur::getWidth() { return 3; }
int Dinosaur::getHeight() { return 4; }
int Dinosaur::getType() { return 2; }


void Dinosaur::test() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			cout << a[i][j];
		}
		cout << endl;
	}
};