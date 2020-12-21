#include "Player.h"

Player::Player() {
	pos.setPos(35, 28);
	drawPlayer();
	isDead = false;
}

Player::Player(Position pos) {
	pos.setPos(pos.getX(), pos.getY());
	drawPlayer();
	isDead = false;
}

Player::~Player() {
	for (int i = 0; i < 2; i++) {
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
	/*
	if (w == 4) {
		if (getX() == pos.getX()) {
			if (pos.getY() <= getY() && getY() - pos.getY() <= 3)
				return true;
			if (pos.getY() >= getY() && pos.getY() - getY() <= 2)
				return true;
		}
	}
	if (w == 3) {
		if (getX() == pos.getX()) {
			if (pos.getY() <= getY() && getY() - pos.getY() <= 2)
				return true;
			if (pos.getY() >= getY() && pos.getY() - getY() <= 2)
				return true;
		}
	}
	*/
	return false;
}

void Player::Up() {
	sound();
	if (pos.getX() <= 3)
		return;
	pos.setPos(pos.getX() - 4, pos.getY());
}

void Player::Down() {
	sound();
	if (pos.getX() + 3 > 34)
		return;
	pos.setPos(pos.getX() + 4, pos.getY());
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
	a = new char* [2];
	emptyPlayer = new char* [2];
	for (int i = 0; i < 2; i++) {
		emptyPlayer[i] = new char[3];
		a[i] = new char[3];
		for (int j = 0; j < 3; j++)
			emptyPlayer[i][j] = ' ';
	}
	a[0][0] = a[0][2] = ' ';
	a[0][1] = 153;
	a[1][0] = 214;
	a[1][1] = 219;
	a[1][2] = 183;
}




