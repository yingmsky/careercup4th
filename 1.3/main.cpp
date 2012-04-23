/*	
    CareerCup 150 Questions 4th
    Solutions to Chapter 1 | Arrays and Strings
    1.3 Design an algorithm and write code to remove the duplicate 
        characters in a string without using any additional buffer. 
        NOTE: One or two additional variables are fine. An extra copy of the array is not.
        FOLLOW UP
        Write the test cases for this method
    [VS2010][2012.04.23][by gboystal]
*/

#include<iostream>
#include<string>
using namespace std;

void removeDuplicates1(char *str)
{
    int tail = 0;
    int j;
    int len = strlen(str);
    for(int i = 0; i < len; i++)
    {
        str[tail] = str[i];
        for(j = 0; j < tail; j++)
            if(str[j] == str[tail]) break;
        if(j == tail) tail++;
    }
    str[tail] = 0;
}

void removeDuplicates2(char *str)
{
    if(str == NULL) return;
    int len = strlen(str);
    bool mark[256];
    memset(mark, false, sizeof(mark));
    
    int tail = 0;
    for(int i = 0; i < len; i++)
    {
        if(mark[str[i]] == false)
        {
            str[tail++] = str[i];
            mark[str[i]] = true;
        }
    }
    str[tail] = 0;
}

int main()
{
    char test[][50] = {"abcd", "aaaa", "", "aaabbb", "abababa"};
    for(int i = 0; i < 5; i++)
    {
        removeDuplicates2(test[i]);
        printf("%s\n", test[i]);
    }

    char *p = NULL;
    removeDuplicates2(p);
    printf("%s\n", p);

    return 0;
}