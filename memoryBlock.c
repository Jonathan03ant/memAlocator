#include "memoryBlock.h"
#include <stdio.h>


memory_blockHeader* head = NULL;
memory_blockHeader* tail = NULL;
pthread_mutex_t global_malloc_lock;


/*
    *Returns a free block of memory of size >= size
    *If no such block is found, returns NULL

*/
memory_blockHeader* get_free_block(size_t size) {
    memory_blockHeader* curr = head;

    while (curr){
        if (curr->mem.is_free && curr->mem.size >= size)
            return curr;
        curr = curr->mem.next;
    }

    return NULL;
}

/*
    *Debugging purpose olnly
    int main() {
    size_t size = 10;

    memory_blockHeader* debug_block = malloc(sizeof(memory_blockHeader));
    debug_block->mem.size = size;
    debug_block->mem.is_free = 1;
    debug_block->mem.next = NULL;

    head = debug_block;

    size_t try = 5;
    memory_blockHeader* block = get_free_block(try);
    if (block == NULL) {
        printf("No free block found.\n");
    } else {
        printf("Free block of size %zu found.\n", block->mem.size);
    }

    free(block);
    return 0;
}
*/
