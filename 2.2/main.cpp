/*	
    CareerCup 150 Questions 4th
    Solutions to Chapter 2 | Linked Lists
    2.2 Implement an algorithm to find the nth to last element of a singly linked list.
    [VS2010][2012.04.26][by gboystal]
*/

#include<iostream>
#include<list>
using namespace std;

struct node
{
    int val;
    node* next;
};

int nthToLast(list<int>& mylist, int nth)
{
    list<int>::iterator it = mylist.end();
    while(nth--) it--;
    return *it;
}

int nthToLast2(node* listhead, int nth)
{
    node* p1 = listhead;
    node* p2 = listhead;

    while(--nth) p2 = p2->next;

    while(p2->next != NULL)
    {
        p1 = p1->next;
        p2 = p2->next;
    };

    return p1->val;
}

int main()
{
    int myints [] = {11, 22, 33, 34, 25, 18, 14, 29};

    //method 1: use STL:list
    list<int> mylist(myints, myints + sizeof(myints) / sizeof(int));
    cout<<nthToLast(mylist, 6)<<endl;
    
    //method 2: use normal linklist
    node* listhead = new node();
    listhead->next = NULL;
    node* p = listhead;
    for(int i = 0; i < 8; i++)
    {
        p->next = new node();
        p->next->val = myints[i];
        p->next->next = NULL;
        p = p->next;
    }
    cout<<nthToLast2(listhead, 6)<<endl;
    return 0;
}