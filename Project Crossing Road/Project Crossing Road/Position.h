#ifndef Position_h
#define Position_h

class Position {
private:
	int X, Y;
public:
	Position() = default;
	Position(const int x, const int y) {
		X = x;
		Y = y;
	}
	int getX()
	{
		return X;
	}
	int getY()
	{
		return Y;
	}
	void setPos(int x, int y) {
		this->X = x;
		this->Y = y;
	}

};

#endif