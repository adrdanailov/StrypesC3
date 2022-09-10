#include "zad1_header.h"

void printarr (char* ch, int start, size_t size)
{
        printf("\n");
        for (int i = 0; i < size; ++i)
            printf("%d: %c \n", i+1, ch[start+i]);
}

int setRandom(char* ch, int start, size_t size, char from, char to)
{

   srand( time( NULL ) );
   for (int i = 0; i < size; ++i) {
      ch[start+i] = randchar(from, to);
   }
   return EXIT_SUCCESS;
}

char randchar (char min, char max)
{
    return min + rand() % (max - min + 1);
}

int setRandom_from_arr(char* ch, int start, size_t size, char* arr)
{
   size_t arr_size = sizeof(arr)/sizeof(arr[0]) - 2; // 0 index
   srand( time( NULL ) );
   for (int i = 0; i < size; ++i) {
      ch[start+i] = arr[randchar(0, arr_size)];
   }
   return EXIT_SUCCESS;
}

int get_lower_caps_count(char* arr)
{
    size_t arr_size = sizeof(arr)/sizeof(arr[0]);
    size_t counter = 0;
    for(int i = 0; i < arr_size; i++)
        arr[i] >= (int)'a' && arr[i] <= (int)'z' ? counter++ : 0 ;
    return counter;
}

char most_freq_char(char *arr, size_t size)
{
  int max = 0;
  char most_freq;
  for(int i = 0 ; i < size ; i++)
  {
    int count = 0;
    for(int j = 0 ; j < size ; j++)
    {
      if(arr[i] == arr[j])
        count++;
    }

    if(count > max)
    {
      max = count;
      most_freq = arr[i];
    }

  }

  return most_freq;
}
