#ifndef _cpeople_h_
#define _cpeople_h_

#include <iostream>

using namespace std;

class CPEOPLE {
private:
	int mX, mY;
	bool mState;
public:
	CPEOPLE();
	void Up(int);
	void Left(int);
	void Right(int);
	void Down(int);
	bool isImpact(const CVEHICLE*&);
	bool isImpact(const CANIMAL*&);
	bool isFinish();
	bool isDead();
};

#endif
