#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

string input_sentence();
int input_colors();
int print(string sentence, int color);
int if_exit();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string sentence = input_sentence();
	system("cls");
	int color = input_colors();
	system("cls");

	if (sentence == "")
	{
		sentence = "Hello, C++!";
	}

	print(sentence, color);

	_getch();
	return 0;
}

string input_sentence()
{
    string sentence;

    cout << "Write a sentence or leave this space empty: ";
    getline(cin, sentence);
    
	return sentence;
}

int input_colors()
{
	int color;

	while (true)
	{
		cout << "Choose a background color (from 0 to 15): ";
		cin >> color;

		if (color > 15 || 0 > color)
		{
			system("cls");
			cout << "Invalid color. Choose a color from 0 to 15: " << endl;
			continue;
		}

		break;
	}

	return color;
}

int print(string sentence, int bg_color)
{
	int text_color = 0;

	cout << "The background color is selected: " << bg_color << endl;
	cout << "TXT " << endl;

	while (text_color < 16)
	{
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 7));
		cout << (text_color < 10 ? "  " : " ") << text_color << " ";
		SetConsoleTextAttribute(hConsole, (WORD)((bg_color << 4) | text_color)); 
		cout << sentence << endl;
		text_color++;
	}

	if_exit();
	return 0;
}

int if_exit()
{
	char answer;
	
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 7));

	cout << "Do you want to exit? (y/n): ";
	cin >> answer;

	if (answer == 'y')
	{
		exit(0);
	}

	main();
	return 0;
}
