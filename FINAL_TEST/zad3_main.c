#include <stdio.h>
#include <stdlib.h>
#include "zad3_header.h"

#define COUNT 10

int main (void)
{
    node_t *linked_list = NULL;
    for (int i = 0; i < COUNT; i++) // fill with random uint64_t
        push(&linked_list, randint(0, RAND_MAX));
    print_list(linked_list);
    printf("\n Pointer to MAX value node %p - %lu", print_max(linked_list), (print_max(linked_list))->data );
    printf("\n Number of '1' bits in llist: %ld\n", print_ones(linked_list));
    listFree(&linked_list);
    return EXIT_SUCCESS;
}
