/*
Strypes C3 cource - Homework 6-7 
Problem 6
Write a function, which performs bubble sort. The prototype of the function is "void Bubble(int* pArray, 
unsigned int uLen)”, where pArary is a pointer to unsorted array and uLen is its size.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void ArrSwap(int *xVal, int *yVal);
void Bubble(int* pArray, unsigned int uLen);
void PrintArr(int arr[], unsigned int uLen);

int main(void)
{
	int arr[] = {23, 11, 100, 5, 42, 30, 0, -1};
	unsigned int uLen = sizeof(arr)/sizeof(arr[0]);
    printf("Unsorted array: \n");
    PrintArr(arr, uLen);
	Bubble(arr, uLen);
	printf("\nSorted array: \n");
	PrintArr(arr, uLen);
    putchar('\n');
	return EXIT_SUCCESS;
}

void ArrSwap(int *xVal, int *yVal) //swapping by reference
{
	int temp = *xVal;
	*xVal = *yVal;
	*yVal = temp;
}

/*bubble sort with optimization if NO swaps on the inner FOR sorting is done - the array is sorted*/
void Bubble(int* pArray, unsigned int uLen)
{
    int i, j, n = uLen - 1; 
    bool swapped;
    for (i = 0; i < n; i++)
    {
        swapped = false;
        for (j = 0; j < n-i; j++)
        {
            if (pArray[j] > pArray[j+1])
            {
                ArrSwap(&pArray[j], &pArray[j+1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

void PrintArr(int arr[], unsigned int uLen)
{
	int i;
	for (i=0; i < uLen; i++)
		printf("%d ", arr[i]);
}
