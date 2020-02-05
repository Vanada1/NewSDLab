#include <iostream>
#include <fstream>
#include <string>
#include "WorkWithFiles.h"

using namespace std;

void TextOutput(string str)
{
	string line;

	ifstream fil(str);
	if (fil.is_open())
	{
		while (getline(fil, line))
		{
			cout << line << endl;
		}
	}
	else
	{
		cout << "Error: cannot open the file";
	}
	fil.close();
}
