#include <iostream>
#include <string>

using namespace std;

#pragma once
class BruteForce
{
public:
	BruteForce(string LookingFor);
	bool Find(string &PasswordOut);
	bool RecursiveFind(int Index, int StringSize, string &Comparison, string &PasswordOut);

	void IsOnlyNumber(bool OnlyNumbers);
	void HasSpecialChars(bool SpecialChars);

private:
	bool Found;
	bool OnlyNumbers, SpecialChars;

	string LookingFor;
	string Comparison;

	int StartChar;
	int EndChar;
};

