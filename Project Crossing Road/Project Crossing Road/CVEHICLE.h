#ifndef _cvehicle_h_
#define _cvehicle_h_

#include <iostream>

using namespace std;

class CVEHICLE {
	int mX, mY;
public:
	virtual void Move(int, int);
	//...
};

#endif
