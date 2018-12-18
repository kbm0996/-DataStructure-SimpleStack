#include "CStack.h"
#include <conio.h>
#include <iostream>
#include <Windows.h>

using namespace std;
using namespace mylib;

int main()
{
	COORD pos = { 0, 0 };
	stack<int> Stack(10);
	int iOut = 0;


	while (1)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

		cout << "## MENU ##" << endl << "1. push" << endl << "2. pop" << endl << "3. peek" << endl << "4. Print" << endl << "5. size" << endl << "6. stacksize" << endl << "7. Exit" << endl << ":";

		if (_kbhit())
		{
			int iInput = _getch();

			switch (iInput)
			{
			case '1':	// push
				cout << "Insert Number : ";
				cin >> iInput;
				if (!Stack.push(iInput))
					cout << "Full" << endl;
				break;
			case '2':	// pop
				if (Stack.pop(&iOut))
					cout << "pop Number : " << iOut << endl;
				else
					cout << "empty" << endl;
				break;
			case '3':	// peek
				if (Stack.peek(&iOut))
					cout << "peek Number : " << iOut << endl;
				else
					cout << "empty" << endl;
				break;
			case '4':	// print
				Stack.Print();
				break;
			case '5':	// size
				cout << "Use Size : " << Stack.size() << endl;
				break;
			case '6':	// stacksize
				cout << "Stack Size : " << Stack.stacksize() << endl;
				break;
			case '7':	// Exit
				return 0;
			default:
				break;
			}

			cout << "Press Any Key" << endl;
			_getch();

			system("cls");
		}
		Sleep(1);
	}

}