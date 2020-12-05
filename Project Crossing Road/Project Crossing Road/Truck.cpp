#include"Truck.h"
using namespace std;


Truck::Truck(Position pos) : Obstacle(pos) {
	a = new char* [1];
	a[0] = new char[4];
	a[0][0] = 220;
	a[0][1] = 220;
	a[0][2] = 219;
	a[0][3] = 219;
};


char **Truck::shape()
{

	return a;
};
void Truck::sound()
{
	PlaySound(TEXT("carstarthonkbackfire.wav"), NULL, SND_ASYNC);
}
Truck::Truck()
{
	a = new char* [1];
	a[0] = new char[4];
	a[0][0] = 220;
	a[0][1] = 220;
	a[0][2] = 219;
	a[0][3] = 219;
}
Truck::~Truck()
{
	for (int i = 0; i < 1; i++)
		delete[] a[i];
	delete[] a;
}
int Truck::getType()
{
	return 4;
}