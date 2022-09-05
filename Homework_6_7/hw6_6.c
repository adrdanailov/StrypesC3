/*
Strypes C3 cource - Homework 6-7 
Problem 6
Write a function, which performs bubble sort. The prototype of the function is "void Bubble(int* pArray, 
unsigned int uLen)”, where pArary is a pointer to unsorted array and uLen is its size.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void arrSwap(int *xVal, int *yVal);
void bubbleSort(int arr[], size_t size);
void printArr(int arr[], size_t size);

int main(void)
{
	int arr[] = {23, 11, 100, 5, 42, 30, 0, -1};
	size_t size = sizeof(arr)/sizeof(arr[0]);
    printf("Unsorted array: \n");
    printArr(arr, size);
	bubbleSort(arr, size);
	printf("\nSorted array: \n");
	printArr(arr, size);
    putchar('\n');
	return EXIT_SUCCESS;
}

void arrSwap(int *xVal, int *yVal) //swapping by reference
{
	int temp = *xVal;
	*xVal = *yVal;
	*yVal = temp;
}

/*bubble sort with optimization if NO swaps on the inner FOR sorting is done - the array is sorted*/
void bubbleSort(int arr[], size_t size)
{
    int i, j, n = size - 1; 
    bool swapped;
    for (i = 0; i < n; i++)
    {
        swapped = false;
        for (j = 0; j < n-i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                arrSwap(&arr[j], &arr[j+1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

void printArr(int arr[], size_t size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
}
