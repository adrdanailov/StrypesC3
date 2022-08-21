#include <stdio.h>

unsigned sumArrayDigits(const int* arr, size_t n);

int main(void)
{
    int array[]={ 12, 34, 5, 70  };
    size_t arr_size = sizeof(array)/sizeof(array[0]);
    printf("\nThe array digital root sum is = %u\n", sumArrayDigits(array, arr_size));
    return 0;
}

unsigned sumArrayDigits(const int* arr, size_t n)
{
    unsigned int sum = 0;
    for (int i = 0; i < n; ++i){
        if ( arr[i] < 10 )
            sum += arr[i];
        else
        {
            unsigned temp = arr[i];
            while (temp != 0) {
                sum += temp % 10;
                temp /= 10;
            }
        }
        //printf("\n%d", ((arr[i])% 10));
    }
return sum;
}
