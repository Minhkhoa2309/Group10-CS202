#ifndef Car_h
#define Car_h

#include "Obstacle.h"


class Car : public Obstacle {
	char** a; //a[2][4]
public:
	Car();
	Car(Position pos);

	~Car();

	char** shape();
	void sound();
	void test();
	int getWidth();
	int getHeight();
	int getType();
};


#endif // !Car_h