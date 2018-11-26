#include <iostream>
#include <windows.h>






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
	return 0;
}