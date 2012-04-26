/*	
    CareerCup 150 Questions 4th
    Solutions to Chapter 2 | Linked Lists
    2.2 Implement an algorithm to find the nth to last element of a singly linked list.
    [VS2010][2012.04.26][by gboystal]
*/

#include<iostream>
#include<list>
using namespace std;

int nthToLast(list<int>& mylist, int nth)
{
    list<int>::iterator it = mylist.end();
    while(nth--) it--;
    return *it;
}

int nthToLast2(list<int>& mylist, int nth)
{
    list<int>::iterator it1 = mylist.begin();
    list<int>::iterator it2 = mylist.begin();
    while(nth--) advance(it2, 1);
    
    while(it2 != mylist.end())
    {
        advance(it1, 1);
        advance(it2, 1);
    };

    return *it1;
}

int main()
{
    int myints [] = {11, 22, 33, 34, 25, 18, 14, 29};
    list<int> mylist(myints, myints + sizeof(myints) / sizeof(int));
    cout<<nthToLast2(mylist, 6)<<endl;
    return 0;
}