#pragma once
#include <iostream>

class Player_Logic
{
	public:
		int moveSpeed = 3;
		bool movingLeft = false;
		bool movingRight = false;
		bool movingUp = false;
		bool movingDown = false;

		Player_Logic();
};
