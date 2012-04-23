/*	
    CareerCup 150 Questions 4th
    Solutions to Chapter 1 | Arrays and Strings
    1.5 Write a method to replace all spaces in a string with ¡®%20¡¯.
    [VS2010][2012.04.23][by gboystal]
*/

#include<iostream>
#include<string>
using namespace std;

void ReplaceFun(char *str, int maxSize)
{
    if(!str) return;
    int len = strlen(str);
    int spaces = 0;
    for(int i = 0; i < len; i++)
        if(str[i] == ' ') spaces++;
    
    int newLen = len + 2 * spaces;
    if(newLen > maxSize) return;
    str[newLen] = 0;

    for(int i = len - 1; i >= 0; i--)
    {
        if(str[i] == ' ')
        {
            str[newLen - 3] = '%';
            str[newLen - 2] = '2';
            str[newLen - 1] = '0';
            newLen -= 3;
        }
        else
        {
            str[newLen - 1] = str[i];
            newLen--;
        }
    }
}

int main()
{
    char test[40] = "ab b cc  ";
    ReplaceFun(test, 40);
    printf("%s\n", test);
    return 0;
}