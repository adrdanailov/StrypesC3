#ifndef _ZAD_3_HEADER_H
#define _ZAD_3_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct node {
    uint64_t data;
    struct node* next;
} node_t;

size_t onesCount(uint64_t x);
size_t print_ones(node_t* list);
node_t* print_max(node_t* list);
uint64_t randint (uint64_t min, uint64_t max);
size_t listSize(node_t*);
void listFree(node_t**);
void print_list(node_t*);
void push(node_t**, int);
#endif
