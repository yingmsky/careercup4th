/*	
    CareerCup 150 Questions 4th
    Solutions to Chapter 1 | Arrays and Strings
    1.4 Write a method to decide if two strings are anagrams or not.
    [VS2010][2012.04.23][by gboystal]
*/

#include<iostream>
#include<string>
using namespace std;

bool anagram1(char *str1, char *str2)
{
    if(!str1 || !str2) return false;
    
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if(len1 != len2) return false;

    int letters[256];
    memset(letters, 0, sizeof(letters));
    for(int i = 0; i < len1; i++)
        letters[str1[i]]++;

    for(int i = 0; i < len2; i++)
        letters[str2[i]]--;

    for(int i = 0; i < 256; i++)
        if(letters[i] != 0) return false;
    return true;
}

bool anagram2(char *str1, char *str2)
{
    if(!str1 || !str2) return false;
    
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if(len1 != len2) return false;

    int letters[256];
    memset(letters, 0, sizeof(letters));

    int num_unique = 0;
    int num_complete = 0;
    for(int i = 0; i < len1; i++)
    {
        if(letters[str1[i]] == 0) num_unique++;
        letters[str1[i]]++;
        
    }
    for(int i = 0; i < len2; i++)
    {
        if(letters[str2[i]] == 0)
        {
            return false;
        }
        letters[str2[i]]--;
        if(letters[str2[i]] == 0)
        {
            num_complete++;
        }
    }
    
    return num_unique == num_complete;
}

int main()
{
    char test1[] = "abbcc";
    char test2[] = "accbb";
    if(anagram2(test1, test2)) printf("anagram\n");
    else printf("non-anagram\n");
    return 0;
}