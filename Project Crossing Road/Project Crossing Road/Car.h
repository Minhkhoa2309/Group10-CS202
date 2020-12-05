#ifndef Car_h
#define Car_h

#include "Obstacle.h"


class Car : public Obstacle {
	char** a; //a[3][8]
public:
	Car();
	Car(Position pos);

	~Car();

	char** shape();
	void sound();
	void test();
	int getWidth() {
		return 8;
	}
	int getType();
};


#endif // !Car_h