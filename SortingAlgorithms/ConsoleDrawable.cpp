#include "ConsoleDrawable.h"

ConsoleDrawable::ConsoleDrawable(const char * info, COORD size, COORD pos, WORD attribute)
{
	information = new CHAR_INFO[size.X * size.Y];
	for (int i = 0; i < size.X * size.Y; i++)
	{
		information[i].Char.AsciiChar = info[i];
		information[i].Attributes = attribute;
	}
	this->size = size;

	this->coordinate.X = 0;
	this->coordinate.Y = 0;

	rect.Left = pos.X;
	rect.Top = pos.Y;
	rect.Right = size.X + rect.Left;
	rect.Bottom = size.Y + rect.Top;
}
ConsoleDrawable::ConsoleDrawable(char * info, COORD size, COORD pos, WORD attribute)
{
	information = new CHAR_INFO[size.X * size.Y];
	for (int i = 0; i < size.X * size.Y; i++)
	{
		information[i].Char.AsciiChar = info[i];
		information[i].Attributes = attribute;
	}
	this->size = size;

	this->coordinate.X = 0;
	this->coordinate.Y = 0;

	rect.Left = pos.X;
	rect.Top = pos.Y;
	rect.Right = size.X + rect.Left;
	rect.Bottom = size.Y + rect.Top;
}

ConsoleDrawable::ConsoleDrawable(char info, COORD size, COORD pos, WORD attribute)
{
	information = new CHAR_INFO[size.X * size.Y];
	for (int i = 0; i < size.X * size.Y; i++)
	{
		information[i].Char.AsciiChar = info;
		information[i].Attributes = attribute;
	}
	this->size = size;

	this->coordinate.X = 0;
	this->coordinate.Y = 0;

	rect.Left = pos.X;
	rect.Top = pos.Y;
	rect.Right = size.X + rect.Left;
	rect.Bottom = size.Y + rect.Top;
}

ConsoleDrawable::ConsoleDrawable(CHAR_INFO * info, COORD size, COORD pos)
{
	information = new CHAR_INFO[size.X * size.Y];
	for (int i = 0; i < size.X*size.Y; i++)
	{
		information[i] = info[i];
	}
	this->size = size;

	this->coordinate.X = 0;
	this->coordinate.Y = 0;

	rect.Left = pos.X;
	rect.Top = pos.Y;
	rect.Right = size.X + rect.Left;
	rect.Bottom = size.Y + rect.Top;
}

ConsoleDrawable::~ConsoleDrawable()
{
	delete[] information;
}

void ConsoleDrawable::move(int x, int y)
{
	rect.Left += x;
	rect.Right += x;

	if (rect.Left < 0)
	{
		rect.Left = 0;
		rect.Right = size.X;
	}

	rect.Top += y;
	rect.Bottom += y;
}

void ConsoleDrawable::setPos(int x, int y)
{
	move(x - rect.Left, y - rect.Top);
}


void ConsoleDrawable::setInfo(WORD info, int start, int end)
{
	for (int i = start; i < end; i++)
	{
		information[i].Attributes = info;
	}
}

