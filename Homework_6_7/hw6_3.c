/*
Strypes C3 cource - Homework 6-7 
Problem 3 
Write a C function which takes as input 8x8 pixels image and returns a vertical mirror of the image. 
Image is monochrome - each pixel is coded as one bit and each byte represents one image row. 
The prototype of the function is: "void VMirror(unsigned char *pImage)". 
Example: 
initial content of buffer : 0x7F,0x40,0x40,0x40,0x7F,0x00,0x00,0x00 
after VMirror execution : 0xFE,0x02,0x02,0x02,0xFE,0x00,0x00,0x00 
*/

#include <stdio.h>
#include <stdlib.h>

#define CHECKBIT(mask,bit) !!(mask & (1 << (bit)))
#define FORIBITS(start, stop) for(int i = (stop); i >= (start); i--)
#define PRINTBITS(a) FORIBITS(0, (CHAR_BIT-1))printf("%d", CHECKBIT((a), i))

void VMirror(unsigned char *pImage);

char mirrorBits(char mask);

int main(void)
{
    unsigned char buffer[] = { 0x7F, 0x40, 0x40, 0x40, 0x7F, 0x00, 0x00, 0x00 };
    VMirror(buffer);
    return EXIT_SUCCESS;
}

char mirrorBits(char mask) // stackoverflow.com (from MSB->LSB to LSB->MSB) in C
{
    char v = mask;
    char r = v & 1; 
    char s = 7;
    for (v >>= 1; v; v >>= 1)
    {   
        r <<= 1;
        r |= v & 1;
        s--;
    }
    r <<= s; 
    return r;
}

void VMirror(unsigned char *pImage)
{   char print_buff;
    for(int i = 0; i<8; i++)
    {   
        {//visualizasion
            print_buff = pImage[i];
            PRINTBITS(print_buff);
            printf("  |  "); 
        }
        pImage[i] = mirrorBits(pImage[i]); //vmirror happens here
        {//visualizasion
            print_buff = pImage[i];
            PRINTBITS(print_buff);
            printf("\n");  
        }
    }
}
