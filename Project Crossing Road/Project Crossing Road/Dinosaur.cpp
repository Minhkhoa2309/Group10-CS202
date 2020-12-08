#include "Dinosaur.h"
using namespace std;


Dinosaur::Dinosaur() {
	a = new char* [2];
	for (int i = 0; i < 2; i++) {
		a[i] = new char[3];
	}
	a[0][0] = (char)32;
	a[0][1] = (char)32;
	a[0][2] = (char)220;
	a[1][0] = (char)220;
	a[1][1] = (char)219;
	a[1][2] = (char)223;
}

Dinosaur::Dinosaur(Position pos) : Obstacle(pos) {
	a = new char* [2];
	for (int i = 0; i < 2; i++) {
		a[i] = new char[3];
	}
	a[0][0] = (char)32;
	a[0][1] = (char)32;
	a[0][2] = (char)220;
	a[1][0] = (char)220;
	a[1][1] = (char)219;
	a[1][2] = (char)223;
};


Dinosaur::~Dinosaur() {
	for (int i = 0; i < 2; i++)
		delete[] a[i];
	delete[] a;
}


char** Dinosaur::shape() { return a; };
void Dinosaur::sound() { PlaySound(TEXT("Dinosaur.wav"), NULL, SND_SYNC); };

int Dinosaur::getWidth() { return 3; }
int Dinosaur::getType() { return 2; }


void Dinosaur::test() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout << a[i][j];
		}
		cout << endl;
	}
};