#include"Car.h"
using namespace std;


Car::Car(Position pos) : Obstacle(pos) {
	a = new char*[1];
	a[0] = new char[4];
	a[0][0] = 220;
	a[0][1] = 219;
	a[0][2] = 219;
	a[0][3] = 220;
};
Car::Car()
{
	a = new char* [1];
	a[0] = new char[4];
	a[0][0] = 220;
	a[0][1] = 219;
	a[0][2] = 219;
	a[0][3] = 220;
}
Car::~Car()
{
	for (int i = 0; i < 1; i++)
		delete[] a[i];
	delete[] a;
}
char **Car::shape()
{

	return a;
}
void Car::sound()
{
	PlaySound(TEXT("trafficjam.wav"), NULL, SND_ASYNC);
}
int Car::getType()
{
	return 1;
}