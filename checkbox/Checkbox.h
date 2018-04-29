#pragma once

#include <string>
#include <Windows.h>
using namespace std;

class Checkbox {
private:
	COORD position;
	short len;

public:
	Checkbox(COORD pos, short len);

	inline short length() { return this->len; };

	COORD getPosition() { return this->position; };

	void draw();


};