#include <stdio.h>   // Needed for printf()
#include <stdlib.h>  // Needed for rand() and srand()
#include <time.h>    // Needed for time() to initialize random seed

int main() {

    // ------------------------------------------------------------
    // 1. INITIALIZATION
    // ------------------------------------------------------------

    // We define the size of our 1D field (10 cells)
    int size = 10;

    // Create an integer array of length 10
    // This array represents our field
    // 0 = empty cell
    // 1 = particle
    int field[10] = {0};  // All elements initialized to 0

    // Place three particles at positions 2, 4, and 6
    field[2] = 1;
    field[4] = 1;
    field[6] = 1;

    // Create a pointer that points to the first element of the array
    // In C, the name of the array already behaves like a pointer
    int *p_field = field;

    // Create a temporary array to store the next state
    int temp[10] = {0};

    // Pointer to the temporary array
    int *p_temp = temp;

    // Initialize random seed using current time
    // This ensures different random values each time the program runs
    srand(time(NULL));

    // Number of simulation steps
    int steps = 10;

    // ------------------------------------------------------------
    // 2. SIMULATION LOOP (DISCRETE TIME STEPS)
    // ------------------------------------------------------------

    for(int t = 0; t < steps; t++) {

        // Print current time step
        printf("Time %d: ", t);

        // Print current field
        for(int i = 0; i < size; i++) {

            // *(p_field + i) means:
            // - move the pointer i positions forward
            // - access the value stored at that address
            printf("%d ", *(p_field + i));
        }
        printf("\n");

        // Before computing next state,
        // we reset the temporary array to 0
        for(int i = 0; i < size; i++) {
            *(p_temp + i) = 0;
        }

        // ------------------------------------------------------------
        // 3. MOVE PARTICLES
        // ------------------------------------------------------------

        for(int i = 0; i < size; i++) {

            // Check if there is a particle at position i
            if(*(p_field + i) == 1) {

                // Generate random movement:
                // rand() % 2 gives 0 or 1
                int direction = rand() % 2;

                int new_position;

                if(direction == 0) {
                    // Move left
                    new_position = i - 1;
                } else {
                    // Move right
                    new_position = i + 1;
                }

                // ----------------------------------------------------
                // 4. HANDLE BOUNDARIES
                // ----------------------------------------------------

                // If particle tries to go outside left boundary
                if(new_position < 0) {
                    new_position = 0;
                }

                // If particle tries to go outside right boundary
                if(new_position >= size) {
                    new_position = size - 1;
                }

                // ----------------------------------------------------
                // 5. HANDLE COLLISIONS
                // ----------------------------------------------------

                // If the new cell is empty in temp array
                if(*(p_temp + new_position) == 0) {

                    // Place particle there
                    *(p_temp + new_position) = 1;

                } else {
                    // Collision detected
                    printf("Collision on index %d\n", new_position);

                    // Remove particle (set to 0)
                    *(p_temp + new_position) = 0;
                }
            }
        }

        // ------------------------------------------------------------
        // 6. COPY TEMP ARRAY BACK TO MAIN FIELD
        // ------------------------------------------------------------

        for(int i = 0; i < size; i++) {
            *(p_field + i) = *(p_temp + i);
        }

        printf("\n");
    }

    return 0;  // End of program
}