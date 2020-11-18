#include<iostream>
#include "ConsoleWindow.h"
using namespace std;


int main()
{
	SetScreenBufferSize(1280, 630);
	resizeConsole(1280, 630);
	//DisableCtrButton(1,1,1); // cai nay bat len la khoi tat may cai nut 
	//ShowScrollbar(0);
	FixConsoleWindow();
	return 0;
}