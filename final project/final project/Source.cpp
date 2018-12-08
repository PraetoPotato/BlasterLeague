//Isaiah Noah P. Santos -100646637
//Hao Tian Guan-100709845
//Eric Aivaliotis-100700292

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define PI 3.14

//forward declare functions
void draw();
void maximizeWindow();
void removeScrollbar();
void ShowConsoleCursor(bool);
void setCursorPosition(int, int);
void randFruitLocation(int &, int &);

int main()
{
	//set the window size
	//console window
	HWND console = GetConsoleWindow();
	// current dimensions
	RECT r;
	GetWindowRect(console, &r);
	//resize to 800x600
	MoveWindow(console, r.left, r.top, 800, 600, TRUE);

	//remove the scrollbar
	removeScrollbar();

	//remove the cursor
	ShowConsoleCursor(false);

	////////////////////////////////////////////////////////////////////////////////////////////////////

	//
	bool end = false;
	while (end == false)
	{
		std::string line;
		std::ifstream snake("SNAKE.txt");
		if (snake.is_open())
		{
			while (getline(snake, line))
			{
				std::cout << line << "\n";
			}
			snake.close();
		}
		else std::cout << "unable to open file" << std::endl;

		std::cout << "\n";
		std::cout << "\n";
		std::cout << "\n";

		std::cout << "Instructions:\n";
		std::cout << "You control a snake that starts out as a dot and you have to eat fruit to grow bigger.\n";
		std::cout << "Try not to collide with the edges of the play area or even yourself if you become to large.\n";

		std::cout << "\n";
		std::cout << "\n";
		std::cout << "\n";

		std::cout << "Controls:\n";
		std::cout << "UP ARROW\tDOWN ARROW\tLEFT ARROW\tRIGHT ARROW\n";

		std::cout << "\n";
		std::cout << "\n";
		std::cout << "\n";

		system("pause");

		system("cls");

		////////////////////////////////////////////////////////////////////////////////////////////////////
		//
		bool endSnake = false;
		while (endSnake == false)
		{
			//declare integers for the snakes coordinates
			std::vector<int> coord_x = { 24/*, 24*/ };
			std::vector<int> coord_y = { 12 + 3/*, 16*/ };
			std::vector<int> dir = { KEY_UP/*, KEY_UP */ };
			//
			std::vector<int> game_x;
			std::vector<int> game_y;
			std::vector<int> game_dir;
			//
			int fruit_x, fruit_y;
			//declare integers for the bounds of the game
			int bound_x(49), bound_y(24 + 3);
			//declare "score" to store the score
			int score = 0;

			//
			srand(time(NULL));
			randFruitLocation(fruit_x, fruit_y);

			//display the game
			draw();

			//draw the initial score
			setCursorPosition(6, 1);
			std::cout << score;

			//draw the initial snake
			for (int counter = 0; counter < coord_x.size(); counter++) {
				setCursorPosition(coord_x[counter], coord_y[counter]);
				std::cout << 'O';
			}

			//draw the initial fruit
			setCursorPosition(fruit_x, fruit_y);
			std::cout << 'F';

			//declare "input" to store input
			int input = 0;

			while (end == false) {
				if (_kbhit()) {
					input = _getch();

					for (int counter = 0; counter < dir.size(); counter++) {
						dir[counter] = input;
						switch (input) {
						case KEY_UP:
							dir[counter] = KEY_UP;
							break;
						case KEY_DOWN:
							dir[counter] = KEY_DOWN;
							break;
						case KEY_LEFT:
							dir[counter] = KEY_LEFT;
							break;
						case KEY_RIGHT:
							dir[counter] = KEY_RIGHT;
							break;
						}
					}

					break;
				}
			}

			//declare "input" to store input
			input = 0;

			int endGame = false;
			while (endGame == false) {
				if (_kbhit())
					input = _getch();

				////////////////////////////////////////////////////////////////////////////////////////////////////

				if (input == 'r') {
					endGame = true;
					break;
				}

				if (input == 'p') {
					input = 0;

					bool endPause = false;
					while (endPause == false) {
						if (_kbhit())
							input = _getch();

						if (input == 'p')
							endPause = true;
					}

					input = 0;
				}

				////////////////////////////////////////////////////////////////////////////////////////////////////

				switch (input) {
				case KEY_UP:
					if (dir[0] == KEY_DOWN)
						break;

					game_x.push_back(coord_x[0]);
					game_y.push_back(coord_y[0]);
					game_dir.push_back(KEY_UP);
					break;
				case KEY_DOWN:
					if (dir[0] == KEY_UP)
						break;

					game_x.push_back(coord_x[0]);
					game_y.push_back(coord_y[0]);
					game_dir.push_back(KEY_DOWN);
					break;
				case KEY_LEFT:
					if (dir[0] == KEY_RIGHT)
						break;

					game_x.push_back(coord_x[0]);
					game_y.push_back(coord_y[0]);
					game_dir.push_back(KEY_LEFT);
					break;
				case KEY_RIGHT:
					if (dir[0] == KEY_LEFT)
						break;

					game_x.push_back(coord_x[0]);
					game_y.push_back(coord_y[0]);
					game_dir.push_back(KEY_RIGHT);
					break;
				}

				////////////////////////////////////////////////////////////////////////////////////////////////////

				for (int counterA = 0; counterA < game_x.size(); counterA++)
					for (int counterB = 0; counterB < coord_x.size(); counterB++)
						if (coord_x[counterB] == game_x[counterA] && coord_y[counterB] == game_y[counterA])
							dir[counterB] = game_dir[counterA];

				////////////////////////////////////////////////////////////////////////////////////////////////////

				if (coord_x[0] == fruit_x && coord_y[0] == fruit_y) {
					switch (dir[dir.size() - 1]) {
					case KEY_UP:
						coord_x.push_back(coord_x[coord_x.size() - 1]);
						coord_y.push_back(coord_y[coord_y.size() - 1] + 1);
						dir.push_back(KEY_UP);
						break;
					case KEY_DOWN:
						coord_x.push_back(coord_x[coord_x.size() - 1]);
						coord_y.push_back(coord_y[coord_y.size() - 1] - 1);
						dir.push_back(KEY_DOWN);
						break;
					case KEY_LEFT:
						coord_x.push_back(coord_x[coord_x.size() - 1] + 1);
						coord_y.push_back(coord_y[coord_y.size() - 1]);
						dir.push_back(KEY_LEFT);
						break;
					case KEY_RIGHT:
						coord_x.push_back(coord_x[coord_x.size() - 1] - 1);
						coord_y.push_back(coord_y[coord_y.size() - 1]);
						dir.push_back(KEY_RIGHT);
						break;
					}

					bool endFruit = false;
					while (endFruit == false) {
						fruit_x = rand() % 48 + 1;
						fruit_y = rand() % 23 + 4;

						endFruit = true;
						for (int counter = 0; counter < coord_x.size(); counter++)
							if (fruit_x == coord_x[counter] && fruit_y == coord_y[counter])
								endFruit = false;
					}

					// update the score
					score += 10;

					setCursorPosition(6, 1);
					std::cout << score;
				}


				////////////////////////////////////////////////////////////////////////////////////////////////////

				for (int counter = 0; counter < coord_x.size(); counter++) {
					switch (dir[counter]) {
					case KEY_UP:
						setCursorPosition(coord_x[counter], coord_y[counter]);
						std::cout << ' ';
						coord_y[counter]--;
						setCursorPosition(coord_x[counter], coord_y[counter]);
						std::cout << 'O';
						//Sleep(100);
						break;
					case KEY_DOWN:
						setCursorPosition(coord_x[counter], coord_y[counter]);
						std::cout << ' ';
						coord_y[counter]++;
						setCursorPosition(coord_x[counter], coord_y[counter]);
						std::cout << 'O';
						//Sleep(100);
						break;
					case KEY_LEFT:
						setCursorPosition(coord_x[counter], coord_y[counter]);
						std::cout << ' ';
						coord_x[counter]--;
						setCursorPosition(coord_x[counter], coord_y[counter]);
						std::cout << 'O';
						//Sleep(100);
						break;
					case KEY_RIGHT:
						setCursorPosition(coord_x[counter], coord_y[counter]);
						std::cout << ' ';
						coord_x[counter]++;
						setCursorPosition(coord_x[counter], coord_y[counter]);
						std::cout << 'O';
						//Sleep(100);
						break;
					}
				}

				Sleep(100);

				////////////////////////////////////////////////////////////////////////////////////////////////////

				bool check = false;

				for (int counterA = 0; counterA < game_x.size(); counterA++) {
					for (int counterB = 0; counterB < coord_x.size(); counterB++) {
						if (coord_x[counterB] == game_x[counterA] && coord_y[counterB] == game_y[counterA]) {
							check = true;
						}
					}

					if (check == false) {
						game_x.erase(game_x.begin() + counterA);
						game_y.erase(game_y.begin() + counterA);
						game_dir.erase(game_dir.begin() + counterA);;
					}

					check = false;
				}

				////////////////////////////////////////////////////////////////////////////////////////////////////

				setCursorPosition(fruit_x, fruit_y);
				std::cout << 'F';

				////////////////////////////////////////////////////////////////////////////////////////////////////

				if (coord_x[0] <= 0 || coord_x[0] >= bound_x || coord_y[0] <= 3 || coord_y[0] >= bound_y) {
					endGame = true;
					endSnake = true;
				}

				for (int counter = 1; counter < coord_x.size(); counter++)
					if (coord_x[0] == coord_x[counter] && coord_y[0] == coord_y[counter]) {
						endGame = true;
						endSnake = true;
					}

				/*if (end == true) {
					end = false;
					break;
				}*/
			}
			//clear the system
			system("cls");
		}

		//clear the system
		system("cls");

		//display game over screen
		std::ifstream game_over("GAME_OVER.txt");
		if (game_over.is_open())
		{
			while (getline(game_over, line))
			{
				std::cout << line << "\n";
			}
			game_over.close();
		}
		else std::cout << "unable to open file" << std::endl;

		std::cout << "\n";
		std::cout << "\n";
		std::cout << "\n";

		//pause the system
		system("pause");

		//clear the system
		system("cls");
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////

	//clear the system 
	system("cls");

	//pause the system
	system("pause");

	//return 0
	return 0;
}

void draw()
{
	std::cout << "///////////////////////////////////////////////////////////////////////////////////////////\n";
	std::cout << "Score\n";
	std::cout << "///////////////////////////////////////////////////////////////////////////////////////////\n";

	char map[26][51];

	for (int row = 0; row < 25; row++)
		for (int col = 0; col < 50; col++) {
			if (row == 0 || row == 24 || col == 0 || col == 49)
				map[row][col] = 'X';
			else
				map[row][col] = ' ';
		}


	for (int row = 0; row < 25; row++) {
		for (int col = 0; col < 50; col++) {
			std::cout << map[row][col];
		}
		std::cout << std::endl;
	}
}

void maximizeWindow()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
}

void removeScrollbar()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	COORD new_size =
	{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(handle, new_size);
}

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

void setCursorPosition(int x, int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}

void randFruitLocation(int &x, int &y)
{
	x = rand() % 48 + 1;
	y = rand() % 23 + 4;
}

