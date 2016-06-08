#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

// This approach requires N (size of the list) + m iterations
// But this could actually be solved in m iterations 
// (think about using additional poiter and combining first and the scond loops)
element* FindMToLastElement(element *head, int m)
{
    int count = 0;
    element *next = head; 
    while (next->next!=0)
    {
    	next = next->next;
    	count++;
    }
    int toSkip = count - m;
    next = head;
    for (int i=0;i<toSkip;i++)
    {
    	next = next->next;
    }
    return next;
}
     
void OneElementTest()
{
    element *head = (element*) malloc (sizeof (element));
    head->next = 0;
    head->data = 10;
    element *last = FindMToLastElement(head,0);
    printf("%d", last->data);
}
    
void TwoElementTest ()
{
    element *head = (element*) malloc (sizeof (element));
    head->next = 0;
    head->data = 10;
    head->next = (element*) malloc (sizeof (element));
    head->next->next = 0;
    head->next->data = 20;
    element *last = FindMToLastElement(head,0);
    printf("%d", last->data);
    element *oneToLast = FindMToLastElement(head,1);
    printf("%d", oneToLast->data);
}

void NullTest() 
{
    element *last = FindMToLastElement(0, 0);
    // this test should pass... - now it causes seg fault
}

void invalidMTest()
{
    element *e1 = (element*) malloc (sizeof (element));
    element *e2 = (element*) malloc (sizeof (element));
    element *e3 = (element*) malloc (sizeof (element));
    e1->data = 1;
    e1->next = e2;
    e2->data = 2;
    e2->next = e3;
    e3->data = 3;
    e3->next = 0;
    
    element *e4 = FindMToLastElement(e1,5);
    // e4 - is the first element but
    // e4 should be NULL since there are only 3 element 
    // but I am requesting 5-th to the last element
}

// this is a little bit more complicated test
// you will need to detect if there is a loop in the linked list
// you will have to find last element of the loop
// and you will need to find m-th to the last elenment
void loopTest()
{
    element *e1 = (element*) malloc (sizeof (element));
    element *e2 = (element*) malloc (sizeof (element));
    element *e3 = (element*) malloc (sizeof (element));
    element *e4 = (element*) malloc (sizeof (element));
    
    e1->data = 1;
    e1->next = e2;
    e2->data = 2;
    e2->next = e3;
    e3->data = 3;
    e3->next = e4;
    e4->data = 4;
    e4->next = e2;
    
    element *e5 = FindMToLastElement(e1,3);
    // results in infinite loop....
}

int main()
{
    OneElementTest();
    TwoElementTest();
	int i;
	scanf("%d",&i);
}
