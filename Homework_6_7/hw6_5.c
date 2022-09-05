/*
Strypes C3 cource - Homework 6-7 
Problem 5
Realize queue from integers with array (ring buffer). Push and Pop function should be realized, e.g.: 
int arr[ MAX_SIZE ]; 
int top = 0; 
int bottom = 0; 
int IsEmpty() - functions returns 0 if queue is empty and > 0 if not 
int IsFull() - function return 0 if the queue is full and new element cannot be added, otherwise > 0 
void Push(int nNewValue) - Functions adds new element to the queue. We assume, that previously 
“IsFull()” was called to check whether is possible to insert element, i.e. it is always possible to insert 
element 
int Pop() - retrieve an element from the queue. We assume that the queue is not empty.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int IsEmpty(void);
int IsFull(void);
void Push(int nNewValue);
int Pop(void);

int arr[ MAX_SIZE ]; 
int top = 0; //Write index
int bottom = 0; //Read index
int buffLenght = 0; //Current size

int main(void)
{
    int i = 0;
    while((IsFull()))
    {
        Push(++i);
    }
    while ((IsEmpty()))
    {
        printf("arr[%d] = %d\n", bottom, Pop());
    }
    return EXIT_SUCCESS;
}

int IsEmpty(void)
{
    if (buffLenght == 0)
    {
        return 0;//buffer is empty
    }else
        return 1;//buffer is not empty
}

int IsFull(void)
{
    if (buffLenght == MAX_SIZE)
    {
        return 0; //buffer is full
    }else
        return 1; //buffer is not full
}

void Push(int nNewValue)
{
    arr[top] = nNewValue;
    buffLenght++;
    top++;
    if (top == MAX_SIZE)  
        top = 0; 
}

int Pop(void)
{
    buffLenght--;
    return arr[bottom++];
}
