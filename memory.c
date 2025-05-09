#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

// Global counter for assigning unique IDs to allocated memory blocks
static int global_block_id = 1;

/*
 * Function: initialize_memory
 * ----------------------------
 * Initializes the simulated memory as a single free block of specified size.
 */
Block* initialize_memory(int total_size) {
    Block* head = (Block*)malloc(sizeof(Block));
    head->block_id = 0;        // 0 indicates the block is free
    head->size = total_size;   // Assign total available memory size
    head->is_free = 1;         // Mark block as free
    head->next = NULL;         // No further blocks yet
    return head;
}

/*
 * Function: merge_free_blocks
 * ----------------------------
 * Scans the memory block list and merges adjacent free blocks into one.
 * This is done to reduce external fragmentation after deallocation.
 */
void merge_free_blocks(Block* head) {
    Block* current = head;
    while (current != NULL && current->next != NULL) {
        // If both current and next blocks are free, merge them
        if (current->is_free && current->next->is_free) {
            current->size += current->next->size; // Add sizes
            Block* temp = current->next;
            current->next = current->next->next; // Remove next block
            free(temp);
        } else {
            current = current->next;
        }
    }
}

/*
 * Function: allocate_memory
 * ----------------------------
 * Allocates memory based on a requested process size and a chosen fit strategy.
 *  First Fit (F): Finds the first block large enough.
 *  Best Fit (B): Finds the smallest suitable block.
 *  Worst Fit (W): Finds the largest suitable block.
 * If a block is larger than required, it splits the block into allocated and free parts.
 * returns: ID of the allocated block, or -1 if allocation fails.
 */
int allocate_memory(Block** head, int process_size, char strategy) {
    Block *current = *head, *selected = NULL, *prev = NULL, *selected_prev = NULL;

    // Iterate through the memory blocks to select suitable one
    while (current != NULL) {
        if (current->is_free && current->size >= process_size) {
            if (strategy == 'F') {
                selected = current;
                selected_prev = prev;
                break;  // First Fit: take first match
            } else if (strategy == 'B') {
                if (selected == NULL || current->size < selected->size) {
                    selected = current;
                    selected_prev = prev;
                }
            } else if (strategy == 'W') {
                if (selected == NULL || current->size > selected->size) {
                    selected = current;
                    selected_prev = prev;
                }
            }
        }
        prev = current;
        current = current->next;
    }

    // No suitable block found
    if (selected == NULL) {
        printf("Allocation failed: No suitable block found.\n");
        return -1;
    }

    // If the block is larger than needed, split it into two
    if (selected->size > process_size) {
        Block* new_block = (Block*)malloc(sizeof(Block));
        new_block->block_id = 0;  // Free
        new_block->size = selected->size - process_size;
        new_block->is_free = 1;
        new_block->next = selected->next;

        selected->size = process_size;
        selected->next = new_block;
    }

    // Finalize allocation
    selected->is_free = 0;
    selected->block_id = global_block_id++;  // Assign unique block ID
    printf("Process allocated with Block ID: %d\n", selected->block_id);
    return selected->block_id;
}

/*
 * Function: deallocate_memory
 * ----------------------------
 * Marks a memory block (by ID) as free, making it available for reuse.
 * After deallocation, it triggers merging of adjacent free blocks to reduce fragmentation.
 * returns: 1 if successful, 0 if block not found.
 */
int deallocate_memory(Block* head, int block_id) {
    Block* temp = head;

    // Traverse to find the block with given ID
    while (temp != NULL) {
        if (temp->block_id == block_id) {
            temp->is_free = 1;
            temp->block_id = 0;  // Reset ID for free block
            merge_free_blocks(head);  // Attempt to merge with neighbors
            printf("Block ID %d deallocated.\n", block_id);
            return 1;
        }
        temp = temp->next;
    }

    // Block ID not found
    printf("Deallocation failed: Block ID %d not found.\n", block_id);
    return 0;
}

/*
 * Function: display_memory
 * Outputs the current memory block list, showing block ID, size, and status (Free/Used).
 * Useful for monitoring the allocation state and fragmentation level.
 */
void display_memory(Block* head) {
    Block* temp = head;

    printf("\nMemory Blocks:\n");
    printf("ID\tSize\tStatus\n");

    while (temp != NULL) {
        printf("%d\t%d\t%s\n", temp->block_id, temp->size,
               temp->is_free ? "Free" : "Used");
        temp = temp->next;
    }
}
