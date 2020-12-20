#include"Car.h"
using namespace std;


Car::Car(Position pos) : Obstacle(pos) {
	a = new char* [2];
	a[0] = new char[4];
	a[1] = new char[4];

	for (int i = 0; i < 4; ++i)
		a[0][i] = 32;

	a[1][0] = a[1][3] = 220;
	a[1][1] = a[1][2] = 219;
};
Car::Car() {
	a = new char* [2];
	a[0] = new char[4];
	a[1] = new char[4];

	for (int i = 0; i < 4; ++i)
		a[0][i] = 32;

	a[1][0] = a[1][3] = 220;
	a[1][1] = a[1][2] = 219;
}
Car::~Car() {
	for (int i = 0; i < 2; i++)
		delete[] a[i];
	delete[] a;
}
char** Car::shape() {
	return a;
}
void Car::sound() {
	PlaySound(TEXT("Car.wav"), NULL, SND_SYNC);
}
int Car::getType() {
	return 1;
}
int Car::getWidth() {
	return 4;
}
int Car::getHeight() {
	return 2;
}
void Car::test() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			cout << a[i][j];
		}
		cout << endl;
	}
}