#include "main.h"


int main() {
	srand(time(NULL));
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	MoveWindow(console, r.left, r.top, 1280, 720, TRUE);
	FixConsoleWindow();

	Game game;
	game.menu();

	// traffic light is good now, top of lane
	// todo:
	//	object drawing
	//	shift crash noti
}