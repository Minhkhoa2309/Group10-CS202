#ifndef Dino_h
#define Dino_h

#include "Obstacle.h"


class Dinosaur : public Obstacle {
	char** a; //a[3][6]
public:
	Dinosaur();
	Dinosaur(Position pos);

	~Dinosaur();

	char** shape();
	void sound();
	void test();
	int getWidth() {
		return 6;
	}
	int getType();
};


#endif