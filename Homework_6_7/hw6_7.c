/*
Strypes C3 cource - Homework 6-7 
Problem 7
Write a function which performs binary search. The prototype of the function is: 
"unsigned int BinSearch(unsigned int *pArray, unsigned int uArraySize, unsigned int uValue)", where 
pArray is pointer to sorted array with ascending order of elements, uArraySize is number of elements in 
the array and uValue is the searched value. If the uValue is found, the function should return it index, 
otherwise 0xFFFF.
*/

#include <stdio.h>
#include <stdlib.h>

#define _NOT_FOUND_ 0xFFFF

void PrintArr(int arr[], unsigned int uLen);
unsigned int BinSearch(unsigned int *pArray, unsigned int uArraySize, unsigned int uValue);

int main(void)
{
	int arr[] = { -1, 0, 5, 11, 23, 30, 42, 100 };
	unsigned int uLen = sizeof(arr)/sizeof(arr[0]);
    unsigned sValue, sIndex;
    printf("Array: \n");
    PrintArr(arr, uLen);
    printf("\nSeach value: ");
    scanf("%d", &sValue);
    sIndex = BinSearch(arr, uLen, sValue);
	if (sIndex == _NOT_FOUND_)
        printf("\n%d is not found in the array\n", sValue);
    else
	    printf("\n%d is located at index Array[%d] \n", sValue, sIndex);
	putchar('\n');
   	return EXIT_SUCCESS;
}

unsigned int BinSearch(unsigned int *pArray, unsigned int uArraySize, unsigned int uValue)
{
    unsigned uStart = 0;
    unsigned uStop = uArraySize - 1;
    while (uStart <= uStop) 
    {
        unsigned middle = uStart + (uStop - uStart) / 2;
        if (pArray[middle] == uValue)
            return middle; 
        
        if (pArray[middle] < uValue)
            uStart = middle + 1; 
        else
            uStop = middle - 1;
    }
    return _NOT_FOUND_;
}

void PrintArr(int arr[], unsigned int uLen)
{
	int i;
	for (i=0; i < uLen; i++)
		printf("%d ", arr[i]);
}
