/*
Strypes C3 cource - Homework 6-7 
Problem 8
Write a function, which performs addition of positive numbers, represented as strings. The result is 
stored into a buffer, passed as parameter to the function. We assume that the result buffer is always big 
enough. The prototype of the function is "void Add(const char* p1, const char* p2, char* result);” 
Example: 
if the function is called as follows: Add( “12345”, “678”, result) , the content of “result” must be 
“13023” or " 13023".
*/

#include <stdio.h>
#include <stdlib.h>

#define _BIG_ENOUGHT_ 1000

void Add(const char* p1, const char* p2, char* result);
void Conv(int sValue, char *pBuffer);

int main(void)
{
    char final_result[_BIG_ENOUGHT_];
    Add("12345","687", final_result);
    printf("\n\"12345\" + \"687\" = \"%s\"\n\n", final_result);
    return EXIT_SUCCESS;
}

void Add(const char* p1, const char* p2, char* result)
{
    unsigned p1_num, p2_num, result_num;
    sscanf(p1, "%u", &p1_num);
    sscanf(p2, "%u", &p2_num);
    result_num = p1_num + p2_num;
    sprintf(result, " %u", result_num);    
}
