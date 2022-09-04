/*
Strypes C3 cource - Homework 6-7
Problem 2
Realize function that reverses null terminated string. The prototype of the function is "void
Reverse(char* ptr);”. Do not use standard library functions.
Example: If e.g. “This is a test\0” is passed to the function, the function must produce “tset a si sihT\0”
*/
#include <stdio.h>

void Reverse(char* ptr);

int main(int argc, char *argv[])
{
    putchar('\n');
    Reverse(argv[1]);
    putchar('\n');
    return 0;
}

void Reverse(char* ptr) //swaping chars
{
    int i = 0, j = 0;
    while(ptr[i] != '\0')
        i++;
    char temp[i];
    do
    {
        temp[j++] = ptr[--i];
    } while(i);
    puts(temp);
}

/*
void Reverse(char* ptr) //using recursion to reverse the string
{
    if(*ptr!='\0')
    {
        Reverse(ptr+1);
        printf("%c", *ptr);
    }
}
*/
