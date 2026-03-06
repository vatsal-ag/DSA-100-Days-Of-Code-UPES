// Given a string s which represents an expression, evaluate this expression and return its value.
// The integer division should truncate toward zero.
// You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].
// Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int calculate(char *s)
{
    int len = strlen(s);

    int *stack = (int *)malloc(len * sizeof(int));
    int top = -1;

    long currentNumber = 0;
    char sign = '+';

    for (int i = 0; i <= len; i++)
    {
        char c = s[i];

        if (isdigit(c))
        {
            currentNumber = (currentNumber * 10) + (c - '0');
        }

        if ((!isdigit(c) && c != ' ') || c == '\0')
        {

            if (sign == '+')
            {
                stack[++top] = currentNumber;
            }
            else if (sign == '-')
            {
                stack[++top] = -currentNumber;
            }
            else if (sign == '*')
            {
                stack[top] = stack[top] * currentNumber;
            }
            else if (sign == '/')
            {
                stack[top] = stack[top] / currentNumber;
            }

            sign = c;
            currentNumber = 0;
        }
    }

    int result = 0;
    for (int i = 0; i <= top; i++)
    {
        result += stack[i];
    }
    free(stack);

    return result;
}