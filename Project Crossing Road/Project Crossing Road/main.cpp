#include "main.h"


int main() {
	srand(time(NULL));
	//DisableMouse();
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	//MoveWindow(window_handle, x, y, width, height, redraw_window);
	MoveWindow(console, r.left, r.top, 1280, 720, TRUE);
	FixConsoleWindow();
	Game game;
	//game.getAllFilename("data");
	game.menu();


	//system("pause");
}