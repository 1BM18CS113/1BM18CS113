#include<stdio.h>

void push(char x, char stack[], int *top)
{
    stack[++(*top)] = x;
}
 
char pop(char stack[], int *top)
{
    if(*top == -1)
        return -1;
    else
        return stack[(*top)--];
}
 
int prec(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}
 
void main()
{
    char stack[20];
    int top = -1;
    char exp[20];
    char *e, x;
    printf("Enter the expression :: ");
    scanf("%s",exp);
    e = exp;
    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c",*e);
        else if(*e == '(')
            push(*e, stack, &top);
        else if(*e == ')')
        {
            while((x = pop(stack, &top)) != '(')
                printf("%c", x);
        }
        else
        {
            while(prec(stack[top]) >= prec(*e))
                printf("%c",pop(stack, &top));
            push(*e, stack, &top);
        }
        e++;
    }
    while(top != -1)
    {
        printf("%c",pop(stack, &top));
    }
}