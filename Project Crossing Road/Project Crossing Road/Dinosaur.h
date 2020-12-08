#ifndef Dino_h
#define Dino_h

#include "Obstacle.h"


class Dinosaur : public Obstacle {
	char** a; // a[2][3]
public:
	Dinosaur();
	Dinosaur(Position pos);

	~Dinosaur();

	char** shape();
	void sound();

	int getWidth();
	int getType();

	void test();
};


#endif