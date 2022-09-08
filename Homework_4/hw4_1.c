#include <stdio.h>
#include <stdint.h>

#define  _ONLY_ONE_ENTRY_ 1
#define  _EMPTY_ -1
#define  _SAME_ENTRIES_ 2


int secondMaxfunc(const int* arr, size_t n, int* secondMax);

int main (void){
    //test cases
    int array[]={ 10, 1, 5, -1, 113, 112 };
    //int array[]={ 1,1,1,1,1,1,1 };
    //int array[]={ 1 };
    //int array[] = {};
    size_t arr_size = sizeof(array)/sizeof(array[0]);
    int secondMax = 0;
    int ret = secondMaxfunc(array, arr_size, &secondMax);

    if (ret == 0){
        printf("\nSecondMAX = %d \n", secondMax);
    }else if(ret>0)
    {
        printf("\nThe array has only one entry: %d", *array);
    }else if (ret == 2)
    { 
        printf("\nThe array has equal entries of: %d s", *array);
    }else
    {
        printf("\nThe array is empty!");
    }
    return 0;
}

int secondMaxfunc(const int* arr, size_t n, int* secondMax) //return -1 empty, 0 OK, 1 all equals
{ 
    int max = arr[0];
    int counter = 0;
    if(n <= 0)
    {        
        return _EMPTY_;
    }else if (n == 1)
    {
        
        return _ONLY_ONE_ENTRY_;
    }else
    {
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > max)
            {
                *secondMax = max;
                max = arr[i];
            }else if (arr[i] == max)
            { 
                counter++;
            }
        }
        if(arr[n-1] != max && arr[n-1] > *secondMax)
            *secondMax = arr[n-1];
    }
        if(counter == n-1)
            return _SAME_ENTRIES_;
    return 0;
}
