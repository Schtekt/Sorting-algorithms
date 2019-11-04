#include "Menu.h"
#include <crtdbg.h>

int main(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	/*HANDLE hStdout, hNewScreenBuffer;
	SMALL_RECT srctWriteRect;
	CHAR_INFO chiBuffer['Z' - 'A' + 1];
	BOOL fSuccess;
	CHAR_INFO tst[5];

	COORD size;
	COORD coord;

	size.X = 'Z' - 'A';
	size.Y = 1;

	coord.X = 0;
	coord.Y = 0;

	srctWriteRect.Top = 0;
	srctWriteRect.Left = 0;
	srctWriteRect.Right = size.X - 1;
	srctWriteRect.Bottom = 1;

	for (int i = 0; i < 'Z' - 'A' + 1; i++)
	{
		chiBuffer[i].Char.AsciiChar = i + 'A';
		chiBuffer[i].Attributes = FOREGROUND_BLUE;
	}

	for (int i = 0; i < 5; i++)
	{
		tst[i].Char.AsciiChar = 'A';
		tst[i].Attributes = FOREGROUND_GREEN;
	}

	// Get a handle to the STDOUT screen buffer to copy from and 
	// create a new screen buffer to copy to. 

	hNewScreenBuffer = CreateConsoleScreenBuffer(
		GENERIC_READ |           // read/write access 
		GENERIC_WRITE,
		FILE_SHARE_READ |
		FILE_SHARE_WRITE,        // shared 
		NULL,                    // default security attributes 
		CONSOLE_TEXTMODE_BUFFER, // must be TEXTMODE 
		NULL);                   // reserved; must be NULL 

	SetConsoleActiveScreenBuffer(hNewScreenBuffer);
	fSuccess = WriteConsoleOutput(hNewScreenBuffer, chiBuffer, size, coord, &srctWriteRect);

	if (!fSuccess)
	{
		printf("WriteConsoleOutput failed - (%d)\n", GetLastError());
		return 1;
	}
	coord.X = 0;
	coord.Y = 0;
	size.X = 5;
	size.Y = 1;
	srctWriteRect.Top = 5;
	srctWriteRect.Bottom = 6;
	fSuccess = WriteConsoleOutput(hNewScreenBuffer, tst, size, coord, &srctWriteRect);

	Sleep(5000);*/

	/*ConsoleGraphics g;

	char tmp[] = { "tst" };
	COORD size;
	size.X = 1;
	size.Y = 3;
	COORD pos;
	pos.X = 5;
	pos.Y = 10;

	ConsoleDrawable tst(tmp, size, pos, BACKGROUND_BLUE);

	g.addToDraw(&tst);
	g.setActive();
	COORD movement = { 0,0 };
	while (true)
	{
		if (GetAsyncKeyState(VK_LEFT))
			movement.X = -1;
		if (GetAsyncKeyState(VK_RIGHT))
			movement.X = 1;
		if (GetAsyncKeyState(VK_UP))
			movement.Y = -1;
		if (GetAsyncKeyState(VK_DOWN))
			movement.Y = 1;
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			break;
		}


		g.draw();
		tst.move(movement.X, movement.Y);
		movement = { 0,0 };
		Sleep(100);
	}*/

	//SortingDisplay disp(60, 30);
	//disp.visualLoop();

	Menu m;
	m.display();
	return 0;
}