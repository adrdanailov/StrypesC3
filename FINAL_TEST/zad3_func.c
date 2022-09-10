#include "zad3_header.h"

size_t onesCount(uint64_t x)
{
    size_t count;
    for (count = 0; x; count++)
        x &= x - 1ull;
    return count;
}

size_t print_ones(node_t* list)
{
    node_t* current = list;
    size_t ones_counter = 0;
    while (current){
        ones_counter += onesCount(current->data);
        current = current->next;
    }
    putchar('\n');
    return ones_counter;
}

node_t* print_max(node_t* list){
    node_t* current = list;
    node_t* prev = current;
    uint64_t max = current->data;
    while (current){
        if (current->data > max)
        {
            prev = current;
            max = current->data;
            current = current->next;
        }else
            current = current->next;
    }
    putchar('\n');
    return prev;
}

uint64_t randint (uint64_t min, uint64_t max)
{
    return min + rand() % (max - min + 1);
}

void print_list(node_t* list){
    node_t* current = list;
    while (current){
        printf("%lu ", current->data);
        current = current->next;
    }
    putchar('\n');
}

void listFree(node_t** list){
    node_t *current = *list, *prev;
    while (current){
        prev = current;
        current = current->next;
        free(prev);
    }
    *list = NULL;
}

void push(node_t** list, int data){
    node_t* n = malloc(sizeof(node_t));
    n->data = data;
    n->next = *list;
    *list = n;
}

size_t listSize(node_t* list){
    size_t cnt = 0;
    node_t* current = list;
    while (current){
        cnt++;
        current = current->next;
    }
    return cnt++;
}
