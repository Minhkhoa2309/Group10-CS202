#ifndef Truck_h
#define Truck_h

#include "Obstacle.h"


class Truck : public Obstacle {
	char** a; //a[1][4]
public:
	Truck();
	Truck(Position pos);

	~Truck();

	char** shape();
	void sound();
	void test();
	int getWidth() {
		return 8;
	}
	int getType();
};


#endif 