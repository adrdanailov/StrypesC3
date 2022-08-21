#include <stdio.h>
#include <stdint.h>

int secondMaxfunc(const int* arr, size_t n, int* secondMax);


int main (){
//test cases
int array[]={ 10, 1, 5, -1, 113, 112 };
//int array[]={ 1,1,1,1,1,1,1 };
//int array[]={ 1 };
//int array[] = {};
size_t arr_size = sizeof(array)/sizeof(array[0]);
int secondMax = 0;

int ret = secondMaxfunc(array, arr_size, &secondMax);

if (!ret){
  printf("\nSecondMAX = %d \n", secondMax);
}else if(ret>0)
{
  printf("\nThe array has only one entry: %d", *array);
}else
{
  printf("\nThe array is empty!");
}


return 0;

}

int secondMaxfunc(const int* arr, size_t n, int* secondMax) { //return -1 empty, 0 OK, 1 all equals
  int max = arr[0];
  int counter = 0;
  if(n <= 0)
  {
    //printf("\nThe array is empty!");
    return -1;
  }else if (n == 1)
  {
    //printf("\nThe array has only one entry: %d ", *arr);
    return 1;
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
      if(counter == n-1)
        //printf("\nAll values are equal!");
      //printf("\n%d %d", max, *secondMax);
      return 0;
  }

}
