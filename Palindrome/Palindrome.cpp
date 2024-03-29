// Palindrome.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

string toLowerCase(string StringToBeConverted)
{
	string LowerCaseString;
	for (int x = 0; x < StringToBeConverted.length(); x++)
	{
		StringToBeConverted[x] = tolower(StringToBeConverted[x]);
	}
	LowerCaseString = StringToBeConverted;
	return LowerCaseString;
}

string RemoveWhiteSpaces(string ExampleString)
{
	int POS = ExampleString.find(' ');
	if (POS == string::npos)
	{
		return ExampleString;
	}
	while (POS != string::npos)
	{
		ExampleString = ExampleString.erase(POS, 1);
		POS = ExampleString.find(' ');
	}
	return ExampleString;
}

bool isPalindrome(string PalindromeTestString)
{
	//OGString = RemoveWhiteSpaces(OGString);
	//OGString = toLowerCase(OGString);

	PalindromeTestString = RemoveWhiteSpaces(PalindromeTestString);
	PalindromeTestString = toLowerCase(PalindromeTestString);

	// 1) Check that lengths are in fact equal
	if ((PalindromeTestString.length()<2) || (PalindromeTestString[0]!= PalindromeTestString[PalindromeTestString.length()-1]))
	{
		return false;
	}
	// 2) Check the individual characters if you start at the front and back you can do 
	for (int x = 0; x < PalindromeTestString.length()/2; x++)
	{
		if (PalindromeTestString[x] != PalindromeTestString[PalindromeTestString.length() -1 - x])
		{
			return false;
		}
	}
	return true;


}

int main()
{
	vector<string> Palindromes = {"Hannah","Anna","Nitin","Revilo P Oliver","Sara Baras","Alomomola","Meat Eater"} ;
	for (auto x : Palindromes)
	{
		if (isPalindrome(x))
		{
			cout << "Palindrome Mulam " << endl;
		}
		else
		{
			cout << "SAXS!!!" << endl;
		}
	}
	//if (isPalindrome(Palindromes.at(0)))
	//{
	//	cout << "Yup Palindrome My Guy" << endl;
	//}
     
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
