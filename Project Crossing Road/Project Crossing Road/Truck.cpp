#include"Truck.h"


Truck::Truck() {
	a = new char* [2];
	a[0] = new char[4]; 
	a[1] = new char[4];

	for (int i = 0; i < 4; ++i)
		a[0][i] = (char)32;

	a[1][0] = (char)220;
	a[1][1] = (char)220;
	a[1][2] = (char)219;
	a[1][3] = (char)219;
}
Truck::Truck(Position pos) : Obstacle(pos) {
	a = new char* [2];
	a[0] = new char[4];
	a[1] = new char[4];

	for (int i = 0; i < 4; ++i)
		a[0][i] = (char)32;

	a[1][0] = (char)220;
	a[1][1] = (char)220;
	a[1][2] = (char)219;
	a[1][3] = (char)219;
};
Truck::~Truck() {
	for (int i = 0; i < 2; i++)
		delete[] a[i];
	delete[] a;
}
void Truck::test() {
	for (int i = 0; i < 2; i++) {
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
	return 2;
}