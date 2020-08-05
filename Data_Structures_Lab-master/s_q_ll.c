#include<stdio.h>
#include<stdlib.h>

struct node{
	int val;
	struct node *next;
};

typedef struct node* NODE; 

NODE getnode();
NODE insert_end(NODE first, int ele);
NODE display(NODE first);
NODE delete_first(NODE first);
NODE delete_end(NODE first);


void main(){
	
	int choice, ele, pos, choice2;
	NODE first = NULL;
	
	
	//outer do while
	
	do{
		printf("***** 1. QUEUE  2. STACK  3. EXIT  *****\n");
		scanf("%d4", &choice2);
		switch(choice2){
			case 1:
				//HERE
				do{
					printf(" ----- 1. ENQUEUE  2. DEQUEUE  3. DISPLAY  4. EXIT----- \n");
					scanf("%d", &choice);
					
					switch(choice){
						
						
						case 1:
						printf("ENTER THE ELEMENT TO ENQUEUE\n");
						scanf("%d", &ele);						
						first = insert_end(first, ele);
						break;
						
						case 2:
						first = delete_first(first);
						break;
						
						case 3:
						first = display(first);
						break;
						
						
					}
				}while(choice !=4);
				
			
			break;
			
			case 2:
				
				//HERE
				do{
					printf(" ----- 1. PUSH  2. POP  3. DISPLAY  4. EXIT----- \n");
					scanf("%d", &choice);
					
					switch(choice){
						
						
						case 1:
						printf("ENTER THE ELEMENT TO PUSH\n");
						scanf("%d", &ele);						
						first = insert_end(first, ele);
						break;
						
						case 2:
						first = delete_end(first);
						break;
						
						case 3:
						first = display(first);
						break;
						
						
					}
				}while(choice !=4);
			
			break;
		}
		
	}while(choice2 != 3);
}

NODE getnode(){
	NODE cr_node = (NODE)malloc(sizeof(struct node));
	cr_node->next = NULL;
	return cr_node;
}


NODE insert_end(NODE first, int ele){

	NODE temp = getnode();
	temp->val = ele;
	NODE curr = first;

	
	if(first == NULL){
		first = temp;
	}
	else{
		while(curr->next!=NULL){
			curr = curr->next;
		}
		curr->next = temp;
	}
	return first;
}



NODE delete_first(NODE first){
	
	if(first == NULL){
		printf("QUEUE EMPTY\n");
		return first;
	}
	
	else{
		printf("The Value Dequeued is %d\n", first->val);
		NODE temp = first;
		first = first->next;
		free(temp);
		return first;
	}
	
	return first;

}



NODE display(NODE first){
	NODE temp = first;
	
	if(first == NULL){
		printf("EMPTY\n");
		return first;
	}
	
	while(temp->next != NULL){
		printf("%d  ", temp->val);
		temp = temp->next;
	}
	printf("%d  \n", temp->val);
	
	return first;
}

NODE delete_end(NODE first){
	
	NODE temp, prev;
	prev = first;
	temp =first;
	int flag =0;
	
	if(first == NULL){
		printf("STACK UNDERFLOW\n");
		return first;
	}
	else{
		while(temp->next != NULL){
			flag =1;
			prev = temp;
			temp = temp->next;			
		}
		printf("The value popped is %d\n", temp->val);
		if(flag==1){
			prev->next = NULL;
			free(temp);		
			return first;
		}
		else{
			free(temp);
			first = NULL;
			return first;
		}
		
	}
	
	
}

