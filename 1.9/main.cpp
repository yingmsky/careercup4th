/*	
    CareerCup 150 Questions 4th
    Solutions to Chapter 2 | Linked Lists
    1.8 Write code to remove duplicates from an unsorted linked list.
        FOLLOW UP
        How would you solve this problem if a temporary buffer is not allowed?
    [VS2010][2012.04.26][by gboystal]
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void deleteDups(vector<int>& v)
{
    int len = v.size();
    if(len < 2) return;
    sort(v.begin(), v.end());
    
    int newsize = 1;
    for(int i = 1; i < len; i++)
    {
        if(v[i] != v[newsize-1])
        {
            v[newsize++] = v[i];
        }
    }
    while((len--) != newsize) v.pop_back();
}

int main()
{
    int myints [] = {10, 20, 30, 30, 20, 10, 10, 20};
    vector<int> v(myints, myints + sizeof(myints) / sizeof(int));
    deleteDups(v);
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
        cout<<*it<<" ";
    return 0;
}