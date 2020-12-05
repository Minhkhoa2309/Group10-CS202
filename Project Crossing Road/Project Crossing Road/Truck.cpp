#include"Truck.h"
using namespace std;

Truck::Truck(Position pos) : Obstacle(pos) {

	a = new char*[3];
	for (int i = 0; i < 3; i++)
	{
		a[i] = new char[8];
	}
	//Row1
	a[0][0] = (char)218;
	for (int i = 1; i < 7; i++)
		a[0][i] = char(196);
	a[0][7] = (char)191;
	//Row2
	a[1][0] = (char)179;
	for (int i = 1; i < 8; i++)
	{
		if (i == 6)a[1][i] = '[';
		else if (i == 7)a[1][i] = (char)179;
		else
			a[1][i] = ' ';
	}
	//Row3
	a[2][0] = (char)192;
	for (int i = 1; i < 7; i++) {
		if (i == 1 || i == 6)a[2][i] = 'O';
		else
			a[2][i] = (char)196;
	}
	a[2][7] = (char)217;

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
	a = new char*[3];
	for (int i = 0; i < 3; i++)
	{
		a[i] = new char[8];
	}
	//Row1
	a[0][0] = (char)218;
	for (int i = 1; i < 7; i++)
		a[0][i] = char(196);
	a[0][7] = (char)191;
	//Row2
	a[1][0] = (char)179;
	for (int i = 1; i < 8; i++)
	{
		if (i == 6)a[1][i] = '[';
		else if (i == 7)a[1][i] = (char)179;
		else
			a[1][i] = ' ';
	}
	//Row3
	a[2][0] = (char)192;
	for (int i = 1; i < 7; i++) {
		if (i == 1 || i == 6)a[2][i] = 'O';
		else
			a[2][i] = (char)196;
	}
	a[2][7] = (char)217;

}
Truck::~Truck()
{
	for (int i = 0; i < 3; i++)
		delete[] a[i];
	delete[] a;
}
int Truck::getType()
{
	return 4;
}