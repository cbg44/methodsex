#include <stdio.h>
#include <Windows.h>
#include "Checkbox.h"
#include <string>
#include <iostream>

using namespace std;
void hidecursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

int main(int argc, char** argv) {

	HANDLE in = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	INPUT_RECORD ir;
	DWORD count = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	CONSOLE_SCREEN_BUFFER_INFO info;
	string inputTextBox;
	DWORD charnum2;
	bool checked = false;
	CHAR* buf2 = new CHAR[0];
	Checkbox cb1({ 20,10 }, 1);
	cb1.draw();
	hidecursor();
	if (!SetConsoleMode(in, count))
		return -1;


	while (1) {
		ReadConsoleInput(in, &ir, 1, &count);
		switch (ir.EventType) {
		case KEY_EVENT:
			break;
		case MOUSE_EVENT:
			if (ir.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
				if ((ir.Event.MouseEvent.dwMousePosition.X >= cb1.getPosition().X && ir.Event.MouseEvent.dwMousePosition.X < cb1.getPosition().X + cb1.length()) &&
					(ir.Event.MouseEvent.dwMousePosition.Y == cb1.getPosition().Y))
				{
					SetConsoleCursorPosition(out, { ir.Event.MouseEvent.dwMousePosition.X,ir.Event.MouseEvent.dwMousePosition.Y });
					ReadConsoleOutputCharacter(out, buf2 , 2, ir.Event.MouseEvent.dwMousePosition, &charnum2);
					if (buf2[0] != 'V') {
						cout << "V";
						checked = true;
					}
					else if (buf2[0] == 'V') {
						cout << "  ";
						checked = false;
					}

					SetConsoleCursorPosition(out, { ir.Event.MouseEvent.dwMousePosition.X,ir.Event.MouseEvent.dwMousePosition.Y });
					SetConsoleCursorPosition(out, { cb1.getPosition().X + (short)inputTextBox.length(), cb1.getPosition().Y });
				}
				else {
					SetConsoleCursorPosition(out, COORD());
				}
		}
	}





}