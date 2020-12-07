#include<iostream>
#include "ConsoleWindow.h"
#include "Obstacle.h"
#include "Bird.h"
#include "Dinosaur.h"
#include "Player.h"
#include "Position.h"
using namespace std;


int main()
{
	Bird a;
	a.test();
	a.sound();

	Dinosaur b;
	b.test();
	b.sound();

	Car c;
	c.test();
	c.sound();

	Truck d;
	d.test();
	d.sound();
	

	
	return 0;
}