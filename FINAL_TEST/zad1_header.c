#ifndef HEADER_H
#define HEADER_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void printarr(char*, int, size_t);
int setRandom(char*, int, size_t, char, char);
int setRandom_from_arr(char*, int, size_t, char*);
char randchar(char min, char max);
int get_lower_caps_count(char* arr);
char most_freq_char(char *arr, size_t size);

#endif
