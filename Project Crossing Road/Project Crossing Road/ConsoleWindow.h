#ifndef _window_h_
#define _window_h_

#include <iostream>
#include <Windows.h>

void resizeConsole(int width, int height);  // Long 
void FixConsoleWindow(); // Long
void SetColor(int backgound_color, int text_color); // Long
void SetScreenBufferSize(SHORT width, SHORT height); // Long
void ShowScrollbar(BOOL Show); // Long
void DisableCtrButton(bool Close, bool Min, bool Max); // Long

#endif
