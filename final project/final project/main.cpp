#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include<conio.h>//needed for _getch and kbhit

bool gameOver;
bool restart;
int score = 0;
int x(5), y(5),foodX, foodY;
char map[30][50];

void draww(int,int,int,int);
void movement();
void events();
int getFoodCoordX(int);
int getFoodCoordY(int);

int direction=5;



int main()
{

	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 800, 600, TRUE);
	std::string line;

	//This is done to make the game loop after you die
	for (;;)
	{
		system("CLS");
		gameOver = false;
		restart = false;

		x = 5;
		y = 5;
		direction = 5;

		std::cout << " ______   _    _     ___     _    __  ______" << std::endl;
		std::cout << "|  ____| | \\  | |   / _ \\   | |  / / |  ____|" << std::endl;
		std::cout << "| |____  |  \\ | |  / / \\ \\  | |_/ /  | |___" << std::endl;
		std::cout << "|____  | |   \\| | | /___\\ | |  __  | |  ___|" << std::endl;
		std::cout << " ____| | | |\\   | |  ___  | | |  | | | |____" << std::endl;
		std::cout << "|______| |_| \\__| |_|   |_| |_|  |_| |______|" << std::endl;
		std::cout << "\n";
		std::cout << "\n";
		std::cout << "\n";

		std::cout << "Instructions: You control a snake that starts out as a dot and you\n have to eat fruit to grow bigger.  Try not to collide with the edges\n of the play area or even yourself if you become to large.\n";


		std::cout << "\n";
		std::cout << "\n";
		std::cout << "\n";
		std::cout << "Controls: W - up    S - down    A - left   D - right   P- pause   R-reset game\n";

		system("pause");
		system("CLS");

		srand(time(NULL));
		foodX = getFoodCoordX(rand() % 47 + 1);
		foodY = getFoodCoordY(rand() % 27 + 1);

		//The Game loop
		while (gameOver == false)
		{

			draww(x, y, foodX, foodY);
			//the events that will be taking place will keep looping until the key board gets hit
			if (_kbhit())
			{
				movement();
			}
			events();
			

		}
		system("CLS");
		if (restart == true)
		{
		
		}
		else
		{
			std::cout << " ______     ___     __    __   ______ " << std::endl;
			std::cout << "|  ____|   / _ \\   |  \\  /  | |  ____| " << std::endl;
			std::cout << "| | ___   / / \\ \\  |   \\/   | | |___  " << std::endl;
			std::cout << "| ||_  | | /___\\ | | |\\  /| | |  ___|" << std::endl;
			std::cout << "| |__| | |  ___  | | | \\/ | | | |____ " << std::endl;
			std::cout << "|______| |_|   |_| |_|    |_| |______|" << std::endl;

			std::cout << " " << std::endl;

			std::cout << " ______   _     __  ______   ______ " << std::endl;
			std::cout << "|  __  | | |   / / |  ____| |  __  | " << std::endl;
			std::cout << "| |  | | | |  / /  | |___   | |__| | " << std::endl;
			std::cout << "| |  | | | | / /   |  ___|  |  _  _| " << std::endl;
			std::cout << "| |__| | | |/ /    | |____  | | \\ \\ " << std::endl;
			std::cout << "|______| |___/     |______| |_|  \\_\\ " << std::endl;
 			system("pause");
		}
		
		
	}
	
	return 0;
}

void draww(int charX, int charY,int fruitX,int fruitY)
{
	system("CLS");
	std::cout << "*******************************************************************************************\n";
	std::cout << "Score    " << score << "\n";
	std::cout << "*******************************************************************************************\n";

	for (int row = 0;row < 29;row++)
	{

		for (int col = 0;col < 49;col++)
		{
			map[col][row] = ' ';//all the rows and columns are dots
			map[col][0] = 'X';
			map[col][28] = 'X';
			map[0][row] = 'X';
			map[48][row] = 'X';
			map[charX][charY] = 'O';
			if (col == fruitX && row == fruitY)
			{
				map[fruitX][fruitY] = 'F';
			}
			

			std::cout << map[col][row];

		}
		std::cout << std::endl;
		
	}

}


void movement()
{
	char move;
	move = _getch();
	switch (move)
	{
	case'W':
	case 'w':
		direction = 1;
		break;
	case'S':
	case 's':
		direction = 2;
		break;
	case'A':
	case 'a':
		direction = 3;
		break;
	case'D':
	case 'd':
		direction = 4;

		break;
	case 'p':
	case'P':
		system("pause");
		break;

	case 'r':
	case'R':
		gameOver = true;
		restart = true;
		break;
	}
	
}

void events()
{
	switch (direction)
	{
	case 1:
		y--;
		break;
	case 2:
		y++;
		break;
	case 3:
		x--;
		break;
	case 4:
		x++;
		break;
	default:
		break;
	}
	if (x > 47 || x < 1|| y> 27 || y < 1)
	{
		gameOver = true;
	}

}

int getFoodCoordX(int fruitX)
{
	return fruitX;
}

int getFoodCoordY(int fruitY)
{
	return fruitY;
}
//Noah's PseudoCode
//if snake coolides with fruit
/*{
     fruit coordinate changes
	 O++

  }*/



//OCEAN's CODE
//bool endLoop = false;
//while (endLoop == false)
//{
//	int fruitX;
//	int fruitY;
//	bool randLoop = false;
//	while (randLoop == false)
//	{
//		srand(time(NULL));
//		fruitX = rand() % 24;
//		fruitY = rand() % 24;

//		if (map[fruitY][fruitX] != 'S')
//			randLoop = true;
//	}


//	for (int ctrA = 0; ctrA < 30; ctrA++)
//	{
//		for (int ctrB = 0; ctrB <80; ctrB++)
//		{
//			if (ctrA == fruitY && ctrB == fruitX)
//				std::cout << 'F';
//			else
//				std::cout << map[ctrA][ctrB];
//		}
//		std::cout << std::endl;
//	}
//	Sleep(1000);
//}