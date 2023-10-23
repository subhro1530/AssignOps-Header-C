#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100

// Function prototypes
int evaluateExpression(char *expression, int start, int end);
int evaluateTerm(char *expression, int start, int end);
int evaluateFactor(char *expression, int start, int end);

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

    // Evaluate the expression
    int result = evaluateExpression(assignment, 0, strlen(assignment) - 1);

    printf("Result: %d\n", result);

    // Free the allocated memory
    free(assignment);

    return 0; // Exit successfully
}

// Function to evaluate an expression
int evaluateExpression(char *expression, int start, int end)
{
    int current = end;

    // Process each character in the expression from right to left
    while (current >= start)
    {
        if (expression[current] == '+')
        {
            // Find the left and right operands for addition
            int left = evaluateExpression(expression, start, current - 1);
            int right = evaluateTerm(expression, current + 1, end);
            return left + right; // Perform addition
        }
        else if (expression[current] == '-')
        {
            // Find the left and right operands for subtraction
            int left = evaluateExpression(expression, start, current - 1);
            int right = evaluateTerm(expression, current + 1, end);
            return left - right; // Perform subtraction
        }
        current--; // Move to the previous character
    }

    // If no addition or subtraction is found, evaluate the term
    return evaluateTerm(expression, start, end);
}

// Function to evaluate a term
int evaluateTerm(char *expression, int start, int end)
{
    int current = end;

    // Process each character in the term from right to left
    while (current >= start)
    {
        if (expression[current] == '*')
        {
            // Find the left and right operands for multiplication
            int left = evaluateTerm(expression, start, current - 1);
            int right = evaluateFactor(expression, current + 1, end);
            return left * right; // Perform multiplication
        }
        else if (expression[current] == '/')
        {
            // Find the left and right operands for division
            int left = evaluateTerm(expression, start, current - 1);
            int right = evaluateFactor(expression, current + 1, end);
            return left / right; // Perform division
        }
        else if (expression[current] == '%')
        {
            // Find the left and right operands for modulo
            int left = evaluateTerm(expression, start, current - 1);
            int right = evaluateFactor(expression, current + 1, end);
            return left % right; // Perform modulo
        }
        current--; // Move to the previous character
    }

    // If no multiplication, division, or modulo is found, evaluate the factor
    return evaluateFactor(expression, start, end);
}

// Function to evaluate a factor
int evaluateFactor(char *expression, int start, int end)
{
    int current = end;

    // Process each character in the factor from right to left
    while (current >= start)
    {
        if (expression[current] == '^')
        {
            // Find the left and right operands for exponentiation
            int left = evaluateFactor(expression, start, current - 1);
            int right = evaluateFactor(expression, current + 1, end);
            return (int)pow(left, right); // Perform exponentiation
        }
        current--; // Move to the previous character
    }

    // If no exponentiation is found, evaluate the primary
    return atoi(expression + start); // Convert the substring to an integer
}
