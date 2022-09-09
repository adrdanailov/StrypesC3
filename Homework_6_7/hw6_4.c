/*
Strypes C3 cource - Homework 6-7
Problem 4
Write C function which takes signed 16 bit number (int) and convert it into ASCII null terminated
string. Function prototype is "void Conv(int sValue, char *pBuffer)", where pBuffer is pointer to string
buffer. Format of the string should be "-DDDDD", if the number is positive the first character is space.
The string should not contain leading zeroes.
Example:
"-   26"
" 16025"
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void Conv(int sValue, char *pBuffer);
void Conv_ASCII(int sValue, char* pBuffer);

int main(void)
{
    int16_t num;
    char str[7], hard[7];
    printf("Enter num:");
    scanf("%hd", &num);
    Conv(num, str);
    printf("\n\'%s\'", str);
    Conv_ASCII(num, hard);
    printf("\n ASCII:\n\'%s\'", hard);
    putchar('\n');
    return EXIT_SUCCESS;
}

void Conv_ASCII(int sValue, char* pBuffer)//short to ASCII
{
    if(sValue<0)
    {
        pBuffer[0] = '-';
        sValue *= -1;
    }else
        pBuffer[0] = ' ';
    pBuffer[1] = !(sValue/10000) ? (' ') : ((sValue/10000) + '0');
    pBuffer[2] = !(sValue/1000) ? (' ') : ((sValue/1000)%10 +'0');
    pBuffer[3] = !(sValue/100) ? (' ') : ((sValue/100)%10 +'0');
    pBuffer[4] = !(sValue/10) ? (' ') : ((sValue/10)%10 +'0');
    pBuffer[5] = !(sValue) ? ('0') : ((sValue)%10 + '0');
    pBuffer[6] = '\0';
}

void Conv(int sValue, char* pBuffer)//sprintf implementation
{
    char sign = ' ';
    if(sValue<0)
    {
        sign = '-';
        sValue *= -1;
    }
    sprintf(pBuffer, "%c%5d", sign, sValue);
}
