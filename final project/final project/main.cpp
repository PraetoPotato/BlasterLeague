#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include<conio.h>//needed for _getch and kbhit

bool gameOver;
int score = 0;
int x(5), y(5);
char map[30][50];

void draww(int,int);
void movement();
void events();

int direction=5;



int main()
{

	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 800, 600, TRUE);
	std::string line;


	std::ifstream draw("Snake.txt");
	if (draw.is_open())
	{
		while (getline(draw, line))
		{
			std::cout << line << "\n";
		}
		draw.close();
	}

	else std::cout << "unable to open file" << std::endl;
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
	system("CLS");
	
	while (gameOver==false)
	{
		draww(x,y);
		//the events that will be taking place will keep looping until the key board gets hit
		if (_kbhit())
		{
			movement();
		}
		events();
		

	}
	

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



	system("CLS");
	system("pause");
	return 0;
}

void draww(int charX, int charY)
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
	case 'w':
		direction = 1;
		break;
	case 's':
		direction = 2;
	
		break;

	case 'a':
		direction = 3;

		break;
	case 'd':
		direction = 4;
	/*	system("CLS");
		x++;
		draww(x, y);*/
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
	if (x > 48 || x < 0|| y> 28 || y < 0)
	{
		gameOver = true;
	}

}