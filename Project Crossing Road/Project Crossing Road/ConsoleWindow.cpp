#include "ConsoleWindow.h"

// ===================== Old ===================== //

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void SetColor(int backgound_color, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}

void SetScreenBufferSize(SHORT width, SHORT height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD NewSize;
    NewSize.X = width;
    NewSize.Y = height;
    SetConsoleScreenBufferSize(hStdout, NewSize);
}

void ShowScrollbar(BOOL Show)
{
    HWND hWnd = GetConsoleWindow();
    ShowScrollBar(hWnd, SB_BOTH, Show);
}

void DisableCtrButton(bool Close, bool Min, bool Max)
{
    HWND hWnd = GetConsoleWindow();
    HMENU hMenu = GetSystemMenu(hWnd, false);

    if (Close == 1)
    {
        DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
    }
    if (Min == 1)
    {
        DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
    }
    if (Max == 1)
    {
        DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
    }
}


// ===================== New ===================== //

int inputKey() {
	if (_kbhit()) {
		int key = _getch();

		if (key == 224) {	// special key
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else {
		return key_none;
	}

	return key_none;
}


void clrscr() {
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0,0 };
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}

void ShowConsoleCursor(bool showFlag) {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}


void gotoXY(int column, int row) {
	ShowConsoleCursor(false);
	COORD coord;
	coord.X = column;
	coord.Y = row;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int whereX() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}

int whereY() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}


void TextColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void DisableMouse() {
	DWORD prev_mode;
	_In_  HANDLE  hConsoleHandle{};
	_Out_ LPDWORD lpMode = nullptr;
	GetConsoleMode(hConsoleHandle, &prev_mode);
	SetConsoleMode(hConsoleHandle, prev_mode & ~ENABLE_QUICK_EDIT_MODE);
}


void drawTitle() {
	TextColor(14);
	gotoXY(21, 10); cout << "   __________  ____  __________ _____   ________     ____  ____  ___    ____ ";
	gotoXY(21, 11); cout << "  / ____/ __ \\/ __ \\/ ___/ ___//  _/ | / / ____/    / __ \\/ __ \\/   |  / __ \\";
	gotoXY(21, 12); cout << " / /   / /_/ / / / /\\__ \\\\__ \\ / //  |/ / / __     / /_/ / / / / /| | / / / /";
	gotoXY(21, 13); cout << "/ /___/ _, _/ /_/ /___/ /__/ // // /|  / /_/ /    / _, _/ /_/ / ___ |/ /_/ / ";
	gotoXY(21, 14); cout << "\\____/_/ |_|\\____//____/____/___/_/ |_/\\____/    /_/ |_|\\____/_/  |_/_____/  ";
}