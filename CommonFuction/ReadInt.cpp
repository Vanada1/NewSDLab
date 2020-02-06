#include "ReadInt.h"


int  ReadInt()
{
	bool error;
	int number;
	do
	{
		error = false;
		cin >> number;
		if (cin.fail())
		{
			cout << "Wrong\n";
			error = true;
			cin.clear();
			cin.ignore(80, '\n');
		}
	} while (error);
	return number;
}