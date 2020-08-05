#include<stdio.h>

void push(int s[], int *top, int ele);
int pop(int s[], int *top);

void main(){
    char exp[20], e;
    int i, stack[20], top=-1;


    printf("Enter the postfix expression\n");
    gets(exp);

    i=0;
    while(exp[i] != '\0'){
        e = exp[i];

        if(isdigit(e)){
            push(stack, &top, (e - 48));
        }

        else{
            int num1 = pop(stack, &top);
            int num2 = pop(stack, &top);

            switch (e)
            {
                case '+':
                    push(stack, &top, (num1+num2));
                    break;
                
                case '-':
                    push(stack, &top, (num2-num1));
                    break;

                case '*':
                    push(stack, &top, (num1*num2));
                    break;

                case '/':
                    push(stack, &top, (num2/num1));
                    break;

            
                default:
                    break;
            }
        }
        i++;


    }
    
    printf("The result of the Expression is %d", pop(stack, &top));
}

void push(int s[], int *top, int ele){
    s[++(*top)] = ele;
}

int pop(int s[], int *top){
    return s[(*top)--];
}
