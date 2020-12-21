#include"Truck.h"


Truck::Truck() {
	a = new char* [4];
	for (int i = 0; i < 4; ++i)
		a[i] = new char[4];

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j)
			a[i][j] = 32;
	}

	a[3][0] = (char)220;
	a[3][1] = (char)220;
	a[3][2] = (char)219;
	a[3][3] = (char)219;
}
Truck::Truck(Position pos) : Obstacle(pos) {
	a = new char* [4];
	for (int i = 0; i < 4; ++i)
		a[i] = new char[4];

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j)
			a[i][j] = 32;
	}

	a[3][0] = (char)220;
	a[3][1] = (char)220;
	a[3][2] = (char)219;
	a[3][3] = (char)219;
};
Truck::~Truck() {
	for (int i = 0; i < 4; i++)
		delete[] a[i];
	delete[] a;
}
void Truck::test() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << a[i][j];
		}
		cout << endl;
	}
}
char **Truck::shape() {
	return a;
};
void Truck::sound() {
	PlaySound(TEXT("Truck.wav"), NULL, SND_SYNC);
}
int Truck::getType() {
	return 4;
}
int Truck::getWidth() {
	return 4;
}
int Truck::getHeight() {
	return 4;
}