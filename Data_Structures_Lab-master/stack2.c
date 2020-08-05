#include<stdio.h>
#define SIZE 5

void push(int stack[], int, int *);
int pop(int stack[], int *);
void display(int stack[], int *);



void main(){
	
	int stack[SIZE];
	int top = -1, choice, num;
	int *top_p = &top;
	
	do{
		
		printf("*****************************************************\n");
		printf("Enter 1 to push, 2 to pop, 3 to display, 5 to exit\n");
		printf("*****************************************************\n");
		fflush(stdin);
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
			printf("Enter the number to push\n");
			fflush(stdin);
			scanf("%d", &num);
			push(stack, num, top_p);
			break;
			
			case 2:
			pop(stack, top_p);
			break;
			
			case 3:
			display(stack, top_p);
			break;
			
			case 5:
			break;
			
			default:
			printf("INVALID CHOICE\n");
		}
	}while(choice !=5);
}

void push(int s[], int num, int *top_pointer){
	
	if(*top_pointer >=(SIZE-1)){
		printf("Stack Overflow\n");
	}
	
	else{
		(*top_pointer)++;
		s[*top_pointer] = num;		
		printf("PUSH SUCCESFUL\n");
	}
}

int pop(int s[], int *top_pointer){
	
	if(*top_pointer == -1){
		printf("STACK UNDERFLOW\n");
	}
	
	else{
		printf("POP SUCCESSFUL : %d\n", s[*top_pointer]);
		(*top_pointer)--;
		return s[(*top_pointer)+1];
	}
}

void display(int s[], int *top_pointer){
	int i;
	if(*top_pointer == -1){
		printf("STACK EMPTY! PUSH FIRST\n");
	}
	else{
		printf("Displaying the Full Stack\n");
		for(i=0; i<=*top_pointer;i++){
			printf("%d\n", s[i]);
		}
	}
}
