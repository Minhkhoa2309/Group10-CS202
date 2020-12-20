#ifndef Truck_h
#define Truck_h

#include "Obstacle.h"
using namespace std;

class Truck : public Obstacle {
	char** a; //a[2][4]
public:
	Truck();
	Truck(Position pos);

	~Truck();

	char** shape();
	void sound();
	void test();
	int getWidth();
	int getHeight();
	int getType();
};


#endif 