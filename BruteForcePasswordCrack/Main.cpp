#include <iostream>
#include <string>
#include <conio.h>
#include <thread>
#include "BruteForce.h"

using namespace std;

const int START_CHAR = 32;
const int END_CHAR = 127;
bool Found;
string Password, PwordCompare;

int main()
{
	string SearchConditions, TmpNum = "";
	bool Found = false;

	char c;

	cout << "Password: ";

	while ((c = _getch()) != '\n')
	{
		if (c == '\r')
			break;
		else if (c == 8)
			Password.pop_back();
		else
			Password.push_back(c);
	}

	cout << endl << "Searching...." << endl;

	PwordCompare = "";

	/*int leastIndex = PwordCompare.length()-2;
	int curr = PwordCompare.length()-1;
	int maxLeastIndex = PwordCompare.length()-1;
	int Range = START_CHAR;
	int Range2 = START_CHAR;
	bool found = false;

	while (leastIndex >= 0)
	{
		for (int c = START_CHAR; c < END_CHAR; c++)
		{
			PwordCompare[PwordCompare.length() - 1] = (char)c;
			cout << " " << PwordCompare << " ";

			if (PwordCompare == Password)
			{
				cout << "Found match: " << PwordCompare << endl;
				found = true;
				break;
			}
		}

		if (found)
			break;

		PwordCompare[leastIndex] = (char)Range++;

		if (Range > END_CHAR)
		{
			leastIndex--;
			Range = START_CHAR;
			PwordCompare[maxLeastIndex] = (char)Range2++;

			if (leastIndex < 0)
				break;

			if (Range2 > END_CHAR)
				Range = START_CHAR;
		}

		if (leastIndex == maxLeastIndex)
			leastIndex = PwordCompare.length() - 2;

		if (leastIndex < maxLeastIndex)
		{
			leastIndex = PwordCompare.length()-2;
			maxLeastIndex--;

			if (maxLeastIndex < 0)
				break;
		}
	}*/

	Found = false;

	BruteForce cracker(Password);
	cracker.IsOnlyNumber(true);
	cracker.HasSpecialChars(false);

	string CrackedPw = "";

	if (cracker.Find(CrackedPw))
	{
		cout << "Your password is: " << CrackedPw << endl;
	}

	cout << endl << endl; 
	system("pause");
}