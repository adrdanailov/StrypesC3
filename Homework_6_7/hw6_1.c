/*
Strypes C3 cource - Homework 6-7
Problem 1
Write C function which takes 16 bit number and should determine whether exactly one bit in this
number is set. If one bit is set, the function should return "1" otherwise "0". The prototype of function is
"unsigned char CheckBit(unsigned int uValue)".
Example:
Input = 0x0400, Output = 0x01
Input = 0x0600, Output = 0x00
Input = 0x0000, Output = 0x00
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define CHECKBIT(mask,bit) !!(mask & (1u << (bit)))
#define _ONLY_ONE_BIT_SET_ '1'
#define _MULTIPLE_BITS_SET_ '0'
#define _ZERO_BITS_SET_ '0'

unsigned char CheckBit(unsigned int uValue);
unsigned char CheckBit_built_in(unsigned int uValue);

int main(void)
{
    uint16_t num[] = { 0x0400, 0x0600, 0x0000, 0x8000, 0x0100, 0x0180 };

    for(int i=0; i < sizeof(num)/sizeof(num[0]); i++) //
    {
        printf("\nInput = 0x%.4x, Output = 0x%.2x", num[i], (CheckBit(num[i]) - '0'));
        printf("\t = %d", CheckBit_built_in(num[i]) - '0');
    }
    putchar('\n');
}

//own logic implemantaion -> 8 loops for 16 bits
unsigned char CheckBit(unsigned int uValue) //return '1' for single 1 BIT | '0' for else
{
    int flag_ones = 0;
    if (uValue == 0)
        return _ZERO_BITS_SET_;
    for (int i = 0; i<8; i++)
    {
       (CHECKBIT(uValue, i)) | (CHECKBIT(uValue, (i+8))) ? flag_ones++ : 0 ;
       if (flag_ones > 1)
            return _MULTIPLE_BITS_SET_;
    }
    return _ONLY_ONE_BIT_SET_;
}

//build in function implementation -> way shorter and tested !
unsigned char CheckBit_built_in(unsigned int uValue)
{
    if (__builtin_popcount(uValue)==1)
        return _ONLY_ONE_BIT_SET_;
    else
        return _MULTIPLE_BITS_SET_;
}
