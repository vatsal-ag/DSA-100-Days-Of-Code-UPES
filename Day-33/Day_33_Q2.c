// You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
// Evaluate the expression. Return an integer that represents the value of the expression.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdlib.h>
#include <string.h>

int evalRPN(char **tokens, int tokensSize)
{
    int *stack = (int *)malloc(tokensSize * sizeof(int));
    int top = -1;

    for (int i = 0; i < tokensSize; i++)
    {
        char *token = tokens[i];

        if (token[1] == '\0' && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'))
        {

            int op2 = stack[top--];
            int op1 = stack[top--];

            if (token[0] == '+')
            {
                stack[++top] = op1 + op2;
            }
            else if (token[0] == '-')
            {
                stack[++top] = op1 - op2;
            }
            else if (token[0] == '*')
            {
                stack[++top] = op1 * op2;
            }
            else if (token[0] == '/')
            {
                stack[++top] = op1 / op2;
            }
        }
        else
        {
            stack[++top] = atoi(token);
        }
    }

    int result = stack[top];

    free(stack);

    return result;
}