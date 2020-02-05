#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void TextOutput()
{
	//TODO: Ответственности(Done)
	string line;
	//TODO: Naming(Done)
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