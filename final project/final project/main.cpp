#include <iostream>
#include <windows.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */





int main()
{

	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 800, 600, TRUE);
	std::string line;


	std::cout << "Title art logo goes here\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";

	std::cout << "Instructions: You control a snake that starts out as a dot and you\n have to eat fruit to grow bigger.  Try not to collide with the edges\n of the play area or even yourself if you become to large.\n";


	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "Controls: W - up    S - down    A - left   D - right\n";

	system("pause");

	char map[5][5] = { { 'X', 'X', 'X', 'X', 'X' },
	{ 'X', 'S', 'S', 'X', 'X' },
	{ 'X', 'X', 'S', 'X', 'X' },
	{ 'X', 'X', 'S', 'S', 'X' },
	{ 'X', 'X', 'X', 'X', 'X' } };

	bool endLoop = false;
	while (endLoop == false)
	{
		int fruitX;
		int fruitY;
		bool randLoop = false;
		while (randLoop == false)
		{
			srand(time(NULL));
			fruitX = rand() % 4;
			fruitY = rand() % 4;

			if (map[fruitY][fruitX] != 'S')
				randLoop = true;
		}

		system("cls");

		for (int ctrA = 0; ctrA < 5; ctrA++)
		{
			for (int ctrB = 0; ctrB < 5; ctrB++)
			{
				if (ctrA == fruitY && ctrB == fruitX)
					std::cout << 'F';
				else
					std::cout << map[ctrA][ctrB];
			}
			std::cout << std::endl;
		}
		Sleep(1000);
	}




	system("pause");
	return 0;
}