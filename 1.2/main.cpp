/*	
    CareerCup 150 Questions 4th
    Solutions to Chapter 1 | Arrays and Strings
    1.2 Write code to reverse a C-Style String. (C-String means that ¡°abcd¡± 
        is represented as five characters, including the null character.) [VS2010]
*/

#include<iostream>
#include <bitset>
using namespace std;

void reverse(char *str)
{
    char * pt = str;
    char tmp;
    if(str)
    {
        while(*pt) pt++;
        pt--;
        while(pt > str)
        {
            tmp = *str;
            *str++ = *pt;
            *pt-- = tmp;
        }
    }
}

int main()
{
    char test[] = "I'm a string";
    reverse(test);
    printf("%s", test);
    return 0;
}