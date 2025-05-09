#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

/*
 * Main driver function for the Memory Management Simulator.
 * using different fit strategies and visualize the current memory state.
 */
int main() {
    int total_memory, choice, size, id;
    char strategy;
    Block* head = NULL;

    /* Prompt user to enter total memory available for simulation: 
    This can take memory data from the system BIOS reboot.*/
    printf("Enter total memory size: ");
    scanf("%d", &total_memory);

    // Initialize the memory space with a single free block
    head = initialize_memory(total_memory);

    // Menu-driven loop for memory operations
    while (1) {
        // Display user menu
        printf("\nMenu:\n");
        printf("1. Allocate Memory\n");
        printf("2. Deallocate Memory\n");
        printf("3. Display Memory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handle user selection
        switch (choice) {
            case 1:
                // Request size and allocation strategy from user
                printf("Enter process size: ");
                scanf("%d", &size);
                printf("Choose strategy (F: First Fit, B: Best Fit, W: Worst Fit): ");
                scanf(" %c", &strategy);

                // Allocate memory block based on strategy
                allocate_memory(&head, size, strategy);
                break;

            case 2:
                // Request block ID to deallocate
                printf("Enter block ID to deallocate: ");
                scanf("%d", &id);

                // Free the memory associated with the given block ID
                deallocate_memory(head, id);
                break;

            case 3:
                // Display the current memory allocation status
                display_memory(head);
                break;

            case 4:
                // Exit the simulation
                printf("Exiting program.\n");
                exit(0);

            default:
                // Handle invalid input
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
