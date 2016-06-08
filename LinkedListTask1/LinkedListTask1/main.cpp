#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"
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
     
int main()
{
    OneElementTest();
    TwoElementTest();
	int i;
	scanf("%d",&i);
}