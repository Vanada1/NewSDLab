#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void TextOutput()
{
	string line;
	//TODO: Ответственности(Done)
	ifstream file("menu.txt");
	if (file.is_open())
	{
		while (getline(file, line))
		{
			cout << line << endl;
		}
	}
	else
	{
		cout << "Error: cannot open the file";
	}
	file.close();
}