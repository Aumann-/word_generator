#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <Windows.h>

using namespace std;

void genString();



int main()
{
	char choice;

	srand(time(NULL));
	/*
	cout << "Generate string? (y/n) ";
	cin >> choice;

	while (choice == 'y' || choice == 'Y')
	{
		genString();
		cout << "Generate string? (y/n) ";
		cin >> choice;
	}
	*/
	//generate between 1 and 5000 strings
	int times = (rand() % 5000) + 1;

	for (int i = 0; i < times; i++)
	{
		genString();
		Sleep(1000); //sleep for 1 second between each string
	}

	cin.ignore();

	return 0;
}

void genString()
{
	string s;

	bool pushed = false;

	int length = (rand() % 10) + 1;
	
	for (int i = 0; i < length; i++)
	{
		while (!pushed) //if a letter has not been put on string, generate a new one and try again
		{
			int t = rand() % 123;

			//if character is a space
			if(t == 32)
			{
				s.push_back((char)t);
				pushed = true;
			}

			//if is a capital letter
			else if (t >= 65)
			{
				if (t < 91)
				{
					s.push_back((char)t);
					pushed = true;
				}
			}

			//if letter is lower case
			else if (t >= 97)
			{
				if (t < 123)
				{
					s.push_back((char) t);
					pushed = true;
				}
			}

		}//end while
		pushed = false;
	}//end for
	cout << s << endl;
}


