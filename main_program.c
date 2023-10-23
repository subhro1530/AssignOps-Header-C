// main_program.c
#include <stdio.h>
#include <stdlib.h>
#include "assignops.h"

#define MAX_LENGTH 100

int main()
{
    printf("Enter an assignment: ");

    // Allocate memory for the input assignment
    char *assignment = (char *)malloc(MAX_LENGTH * sizeof(char));

    // Check if memory allocation was successful
    if (assignment == NULL)
    {
        printf("Memory allocation failed. Exiting...\n");
        return 1; // Exit with an error code
    }

    // Read the assignment from the user
    fgets(assignment, MAX_LENGTH, stdin);

    // Evaluate the assignment using the function from the header file
    int result = evaluateAssignment(assignment);

    printf("Result: %d\n", result);

    // Free the allocated memory
    free(assignment);

    return 0; // Exit successfully
}
