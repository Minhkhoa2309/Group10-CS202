#include <iostream>
#include "ConsoleWindow.h"
#include "Obstacle.h"
#include "Bird.h"
#include "Dinosaur.h"
#include "Player.h"
#include "Position.h"
using namespace std;

bool constantVar::isMute = false;
bool constantVar::isHard = true;


int main()
{
	Bird a;
	a.test();
	a.sound();
	cout << endl;

	Dinosaur b;
	b.test();
	b.sound();
	cout << endl;

	Car c;
	c.test();
	c.sound();
	cout << endl;

	Truck d;
	d.test();
	d.sound();
	cout << endl;
	

	
	return 0;
}