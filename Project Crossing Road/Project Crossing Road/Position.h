#ifndef Position_h
#define Position_h


class Position {
private:
	int X, Y;
public:
	Position() {};
	Position(const int x, const int y) {
		X = x;
		Y = y;
	}

	~Position() {};
	
	int getX();
	int getY();
	
	void setPos(int x, int y) {
		this->X = x;
		this->Y = y;
	}
};


#endif // Position