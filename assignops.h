// assignops.h

#ifndef ASSIGNOPS_H
#define ASSIGNOPS_H

// Function prototypes
int evaluateAssignment(char *assignment);
int evaluateExpression(char *expression, int start, int end);
int evaluateTerm(char *expression, int start, int end);
int evaluateFactor(char *expression, int start, int end);

#endif
