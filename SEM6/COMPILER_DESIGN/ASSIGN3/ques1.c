#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

struct stack
{
    char Stack[MAX];
    int top;
} s;

void push(char value)
{
    if (s.top == (MAX - 1))
        printf("Stack is Full\n");
    else
    {
        s.top = s.top + 1; // Push the char and increment top
        s.Stack[s.top] = value;
    }
}

void pop()
{
    if (s.top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        s.top = s.top - 1; // Pop the char and decrement top
    }
}

int main()
{

    int choice;
    while (1)
    {
        printf("Enter 0 to exit \n");
        scanf("%d", &choice);
        if (choice == 0)
            break;

        char str[MAX];
        int i = 0;
        s.top = -1;
        printf("\nEnter the expression to be checked : ");
        scanf("%s", str);

        for (i = 0; i < strlen(str); i++)
        {
            if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            {
                push(str[i]); // Push the open bracket
                continue;
            }
            else if (str[i] == ')' || str[i] == ']' || str[i] == '}') // If a closed bracket is encountered
            {
                if (str[i] == ')')
                {
                    if (s.Stack[s.top] == '(')
                    {
                        pop(); // Pop the stack until closed bracket is found
                    }
                    else
                    {
                        printf("\nUnbalanced\n");
                        break;
                    }
                }
                if (str[i] == ']')
                {
                    if (s.Stack[s.top] == '[')
                    {
                        pop(); // Pop the stack until closed bracket is found
                    }
                    else
                    {
                        printf("\nUnbalanced\n");
                        break;
                    }
                }
                if (str[i] == '}')
                {
                    if (s.Stack[s.top] == '{')
                    {
                        pop(); // Pop the stack until closed bracket is found
                    }
                    else
                    {
                        printf("\nUnbalanced\n");
                        break;
                    }
                }
            }
        }
        if (s.top == -1)
        {
            printf("\nBALANCED \n"); // Finally if the stack is empty, display that the expression is balanced
        }
        else
        {
            printf("\nUnbalanced\n");
        }
    }
    return 0;
}