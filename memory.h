#ifndef MEMORY_H
#define MEMORY_H

/*
 * Struct: Block
 * ----------------------------
 * Represents a continuous block of memory in the simulated memory space.
 * Each block contains metadata including:
 * - block_id
 * - size
 * - is_free: Flag indicating whether the block is free (1) or allocated (0).
 * - next: Pointer to the next block 
 *
 *  singly linked list .
 */
typedef struct Block {
    int block_id;          // Unique ID 
    int size;              // Size of the memory block
    int is_free;           
    struct Block* next;    
} Block;

/*
 * Initializes the memory with a single large free block.
 * returns: A pointer to the head of the block list.
 */
Block* initialize_memory(int total_size);

/*
 * Function: allocate_memory
 * ----------------------------
 * Allocates a memory block of given process size using the selected strategy.
 * process_size: Size of the memory block requested by the process.
 * strategy: Allocation strategy ('F' = First Fit, 'B' = Best Fit, 'W' = Worst Fit).
 * returns: The block_id assigned to the allocated block or -1 if allocation fails.
 */
int allocate_memory(Block** head, int process_size, char strategy);

/*
 * Function: deallocate_memory
 * returns: 1 if successful, 0 if block ID not found.
 */
int deallocate_memory(Block* head, int block_id);

/*
 * Function: display_memory
 * Prints the current state of the memory blocks to stdout.
 * Useful for debugging and visualizing memory allocation.
 */
void display_memory(Block* head);

/*
 * Function: merge_free_blocks
 * Merges adjacent free blocks into a single larger block.
 * Reduces external fragmentation in the simulated memory.
 */
void merge_free_blocks(Block* head);

#endif  // MEMORY_H
/*
*This code simulates low-level memory management using dynamic allocation 
strategies (First Fit, Best Fit, Worst Fit) by 
modeling memory as a linked list of blocks. 
*It is essential for understanding 
how operating systems handle process memory 
allocation and fragmentation.
*It can be used for educational purposes, OS development practice, 
or embedded system memory simulation where hardware-level allocation 
behavior is mimicked.
*/