#ifndef Bird_h
#define Bird_h

#include "Obstacle.h"


class Bird : public Obstacle {
	char** a; //a[3][6]
public:
	Bird();
	Bird(Position pos);

	~Bird();

	char** shape();
	void sound();
	void test();
	int getWidth() {
		return 6;
	}
	int getType();
};


#endif