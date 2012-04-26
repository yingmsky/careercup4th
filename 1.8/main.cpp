/*	
    CareerCup 150 Questions 4th
    Solutions to Chapter 1 | Arrays and Strings
    1.8 Assume you have a method isSubstring which checks if one word is a substring of another. 
        Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only
        one call to isSubstring (i.e., ¡°waterbottle¡± is a rotation of ¡°erbottlewat¡±).
    [VS2010][2012.04.23][by gboystal]
*/

#include<iostream>
#include<string>
using namespace std;

bool isSubstring(string s1, string s2)
{
    return s1.find(s2) != string::npos;
}

bool isRotation(string s1, string s2)
{
    if(s1.length() != s2.length() || s1.length() == 0) return false;
    string tmp = s1 + s1;
    return isSubstring(tmp, s2);

}
int main()
{
    if(isRotation("erbottlewat", "waterbottle")) printf("yes!\n");
    else printf("no!\n");
    return 0;
}