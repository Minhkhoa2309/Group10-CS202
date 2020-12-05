#include "Player.h"

Player::Player() {
	pos.setPos(34, 28);
	drawPlayer();
	isDead = false;
}

Player::Player(Position pos) {
	pos.setPos(pos.getX(), pos.getY());
	drawPlayer();
	isDead = false;
}

Player::~Player() {
	for (int i = 0; i < 3; i++) {
		delete[] a[i];
		delete[] emptyPlayer[i];
	}
	delete[] a;
	delete[] emptyPlayer;
}

Position Player::getPos() {
	return pos;
}

int Player::getX() {
	return pos.getX();
}

int Player::getY() {
	return pos.getY();
}

int Player::getWidth() {
	return width;
}

int Player::getHeight() {
	return height;
}

char** Player::shape() {
	return a;
}

char** Player::emptyShape() {
	return emptyPlayer;
}

bool Player::IsDead() {
	return isDead;
}

bool Player::crash(Position pos, int w, int h) {
	if (w == 5) {
		//crash while Car/Truck on the right
		if (getX() == pos.getX()) {
			if (getY() <= pos.getY() && max(getY(), pos.getY()) <= min(getY() + getWidth() - 3, pos.getY() + w - 3))
				return true;
			if (getY() >= pos.getY() && getY() - pos.getY() <= 3)
				return true;
		}
	}
	if (w == 3) {
		if (getX() == pos.getX()) {
			if (getY() >= pos.getY() && pos.getY() + w - 1 >= getY()) // crash while bird on the left
				return true;
			if (getY() <= pos.getY() && pos.getY() - getY() <= 2) //crash while bird on the right
				return true;
		}
	}
	else
		if (getX() == pos.getX() && max(getY(), pos.getY()) <= min(getY() + getWidth() - 3, pos.getY() + w - 3)) 
			return true;
	return false;
}

void Player::Up() {
	sound();
	if (pos.getX() <= 3)
		return;
	pos.setPos(pos.getX() - 3, pos.getY());
}

void Player::Down() {
	sound();
	if (pos.getX() + 3 > 34)
		return;
	pos.setPos(pos.getX() + 3, pos.getY());
}

void Player::Left() {
	sound();
	if (pos.getY() <= LEFTMAP) 
		return;
	pos.setPos(pos.getX(), pos.getY() - 1);
}

void Player::Right() {
	sound();
	if (pos.getY() + 2 >= RIGHTMAP) 
		return;
	pos.setPos(pos.getX(), pos.getY() + 1);
}

void Player::gotHit() {
	isDead = true;
}

void Player::sound() {
//	if (!constantVar::isMute && !isDead)
//		PlaySound(TEXT("RING.wav"), NULL, SND_ASYNC);
}

void Player::drawPlayer() {
	a = new char* [3];
	emptyPlayer = new char* [3];
	for (int i = 0; i < 3; i++) {
		emptyPlayer[i] = new char[5];
		a[i] = new char[5];
		for (int j = 0; j < 5; j++)
			emptyPlayer[i][j] = ' ';
	}

	for (int i = 0; i < 5; i++) {
		if (i == 2)
			a[0][i] = 'O';
		else
			a[0][i] = ' ';
	}

	a[1][0] = '/';
	a[1][1] = '(';
	a[1][2] = '_';
	a[1][3] = ')';
	a[1][4] = '\\';

	for (int i = 0; i < 5; i++) {
		if (i == 1)
			a[2][i] = '/';
		else if (i == 3)
			a[2][i] = '\\';
		else a[2][i] = ' ';
	}
}




