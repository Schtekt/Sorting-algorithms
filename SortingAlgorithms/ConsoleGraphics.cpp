#include "ConsoleGraphics.h"
#include <iostream>
ConsoleGraphics::ConsoleGraphics()
{
	first = CreateConsoleScreenBuffer(GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	second = CreateConsoleScreenBuffer(GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
}

ConsoleGraphics::~ConsoleGraphics()
{
	for (int i = 0; i < toDraw.size(); i++)
	{
		delete toDraw[i];
	}
}

void ConsoleGraphics::setActive()
{
	SetConsoleActiveScreenBuffer(first);
	active = &first;
}

void ConsoleGraphics::addToDraw(ConsoleDrawable* drawable)
{
	toDraw.push_back(drawable);
}

void ConsoleGraphics::draw()
{
	DWORD charsWritten;
	for (int i = 0; i < toDraw.size(); i++)
	{
		WriteConsoleOutput(*active, toDraw[i]->information, toDraw[i]->size, toDraw[i]->coordinate, &toDraw[i]->rect);
	}
	SetConsoleActiveScreenBuffer(*active);
	if (active == &first)
		active = &second;
	else
		active = &first;
	clear(120*30);
}

void ConsoleGraphics::clear(int numberOfChars)
{
	DWORD charsWritten;
	FillConsoleOutputCharacter(*active, (TCHAR)' ', numberOfChars, { 0,0 }, &charsWritten);
	FillConsoleOutputAttribute(*active, NULL, numberOfChars, { 0,0 }, &charsWritten);
}


