#ifndef SWAP_H
#define SWAP_H

void swap(int* num1, int* num2)
{
    *num1 ^= *num2;
    *num2 ^= *num1;
    *num1 ^= *num2;
}

#endif