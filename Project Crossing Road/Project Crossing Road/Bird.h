#ifndef Bird_h
#define Bird_h

#include "Obstacle.h"


class Bird : public Obstacle {
	char** a; // a[2][3]
public:
	Bird();
	Bird(Position pos);

	~Bird();

	char** shape();
	void sound();
	void test();
	int getWidth() {
		return 3;
	}
	int getType();
};


#endif