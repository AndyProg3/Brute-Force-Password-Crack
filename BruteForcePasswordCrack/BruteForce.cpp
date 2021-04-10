#include "BruteForce.h"

BruteForce::BruteForce(string LookingFor)
{
	Found = false;
	OnlyNumbers = false;
	SpecialChars = true;

	this->LookingFor = LookingFor;
	Comparison = "";

	//Starting value for compare
	for (int d = 0; d < LookingFor.length(); d++)
	{
		Comparison += " ";
	}
}

void BruteForce::IsOnlyNumber(bool OnlyNumbers)
{ this->OnlyNumbers = OnlyNumbers; }

void BruteForce::HasSpecialChars(bool SpecialChars)
{ this->SpecialChars = SpecialChars; }

bool BruteForce::Find(string &PasswordOut)
{
	if (OnlyNumbers)
	{
		StartChar = 48;
		EndChar = 58;
	}
	else
	{
		StartChar = 32;
		EndChar = 127;
	}

	return RecursiveFind(0, LookingFor.length(), Comparison, PasswordOut);
}

bool BruteForce::RecursiveFind(int Index, int StringSize, string &Comparison, string &PasswordOut)
{
	bool Search = true;

	for (int c = StartChar; c < EndChar; c++)
	{
		if (!SpecialChars)
		{
			if ((c <= 47 && c >= 32) ||
				(c <= 64 && c >= 58))
				Search = false;
			else
				Search = true;
		}

		if (Found)
			return true;

		if (Search)
		{
			if (Index + 1 < StringSize)
				RecursiveFind(Index + 1, StringSize, Comparison, PasswordOut);

			Comparison[Index] = (char)c;
			//cout << PwordCompare << " ";

			if (Comparison == LookingFor)
			{
				Found = true;
				PasswordOut = Comparison;
				return true;
			}
		}
	}

	return false;
}