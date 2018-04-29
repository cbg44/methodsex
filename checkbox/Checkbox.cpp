#include "Checkbox.h"
#include <iostream>

Checkbox::Checkbox(COORD pos, short len) {
	this->position = pos;
	this->len = len;
}

void Checkbox::draw() {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(out, &info);
	SetConsoleCursorPosition(out, { this->position.X - 2,this->position.Y - 1 });
	cout << '\xC9';
	for (int i = 0; i < 3; i++)
		cout << '\xCD';
	cout << '\xBB';
	SetConsoleCursorPosition(out, { this->position.X - 2,this->position.Y });
	cout << '\xBA';
	for (int i = 0; i < 3; i++)
		cout << ' ';
	cout << '\xBA';
	SetConsoleCursorPosition(out, { this->position.X - 2,this->position.Y + 1 });
	cout << '\xC8';
	for (int i = 0; i < 3; i++)
		cout << '\xCD';
	cout << '\xBC';

	SetConsoleTextAttribute(out, info.wAttributes);

	SetConsoleCursorPosition(out, info.dwCursorPosition);
}
