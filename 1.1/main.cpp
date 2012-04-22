/*	
	CareerCup 150 Questions 4th
	Solutions to Chapter 1 | Arrays and Strings
	1.1 Implement an algorithm to determine if a string has all unique characters. What if you can not use additional data structures? [VS2010]
*/

#include<iostream>
#include <bitset>
using namespace std;

bool isUniqueChars1(string str)
{
	bool char_set[256];
	memset(char_set, false, sizeof(char_set));
	for(int i = 0; i < str.length(); i++)
	{
		if(char_set[str[i]] == true) return false;
		char_set[str[i]] = true;
	}
	return true;
}

bool isUniqueChars2(string str)
{
	bitset<256> mybits;
	mybits.reset();
	for(int i = 0; i < str.length(); i++)
	{
		if(mybits[str[i]] == 1) return false;
		mybits[str[i]] = true;
	}
	return true;
}

int main()
{
	string test[] = {"careercup", "Diablo"};
	for(int i = 0; i < 2; i++)
	{
		cout<<test[i]<<" --> ";
		if(isUniqueChars2(test[i])) cout<<"true";
		else cout<<"false";
		cout<<endl;
	}
	return 0;
}