#include<stdio.h>
#define MAX 3

void enqueue(int q[], int *);
void dequeue(int q[], int *, int *);
void display(int q[], int *, int *);

void main(){
	
	int choice, queue[MAX], f = 0, r = -1;
	
	do{	
		printf("**********************************************\n");
		printf("1. Enqueue\n2. Dequeue\n3. Display\n5. Exit\n");
		printf("**********************************************\n");
		fflush(stdin);
		scanf("%d", &choice);
		
		switch(choice){
		
		case 1:
		enqueue(queue, &r);
		break;
		
		case 2:
		dequeue(queue, &f, &r);
		break;
		
		case 3:
		display(queue, &f, &r);
		break;
		
		case 5:
		break;
		
		default:
		printf("Invalid Choice\n");
		
		}
	}while(choice!=5);
}

void enqueue(int q[], int *r){
	
	int num;
	if(*r == (MAX-1))
		printf("QUEUE is FULL\n");
	else{
		printf("Enter the number to push\n");
		fflush(stdin);
		scanf("%d", &num);
		q[++(*r)] = num;
		printf("PUSH SUCCESFUL\n");
	}

}

void dequeue(int q[], int *f, int *r){
	
	if(*f > *r)
		printf("QUEUE EMPTY\n");
	else{
		printf("%d\n", q[(*f)++]);
	}

}


void display(int q[], int *f, int *r){

	int i;
	
	if(*f >*r){
		printf("QUEUE EMPTY\n");
	}
	
	else{
		for(i = *f; i<=*r; i++){
			printf("%d\n", q[i]);
		}
	}
	
}
