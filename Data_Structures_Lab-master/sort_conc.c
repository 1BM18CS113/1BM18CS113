#include<stdio.h>
#include<stdlib.h>


struct node{
	int data;
	struct node* next;
};

typedef struct node* NODE;


NODE getnode();
NODE insert_beg(NODE first, int ele);
NODE concatenate(NODE first1, NODE first2);
NODE display(NODE first);
NODE insert_end(NODE first, int ele);
NODE sort_list(NODE first);


void main(){
	
	int ele, n2, n1;
	NODE first1 = NULL;
	NODE first2 = NULL;
	
	
	printf("Enter size of list 1\n");
	scanf("%d", &n1);
	for(int i = 0; i<n1; i++){
		printf("Enter list element %d\n", (i+1));
		scanf("%d", &ele);
		first1 = insert_end(first1, ele);
	}
	
	
	printf("Enter size of list 2\n");
	scanf("%d", &n2);
	for(int i = 0; i<n2; i++){
		printf("Enter list element %d\n", (i+1));
		scanf("%d", &ele);
		first2 = insert_end(first2, ele);
	}
	
	first1 = concatenate(first1, first2);
	printf("THE LIST AFTER CONCAteNATION IS:\n");
	display(first1);
	
	
	first1 = sort_list(first1);
	//printf("**************************");
	printf("List after sorting is :\n");
	display(first1);
	//printf("IN DO WHILE");
	
	/**switch(choice){
		case 1:
		printf("ENTER THE ELEMENT TO INSERT AT THE BEGINNING\n");
		scanf("%d", &ele);
		
		first = insert_beg(first, ele);
		break;
		
		case 2:
		printf("ENTER THE ELEMENT TO INSERT AT THE END\n");
		scanf("%d", &ele);
		
		first = insert_end(first, ele);
		break;
		
		case 3:
		first = display(first);
		break;
		
		case 4:
		printf("ENTER THE ELEMENT TO INSERT AT THE END\n");
		scanf("%d", &ele);
		
		printf("ENTER THE Position TO INSERT\n");
		scanf("%d", &pos);
		
		first = insert_any_pos(first, ele, pos);
		break;
		
		case 5:
		first = delete_first(first);
		break;
		
		case 6:
		first = delete_end(first);
		break;
		
		case 8:
		printf("ENTER THE Position TO DELETE\n");
		scanf("%d", &pos);
		first = delete_any_pos(first, pos);
		break;
	}**/
	
}


NODE getnode(){
	NODE cr_node = (NODE)malloc(sizeof(struct node));
	cr_node->next = NULL;
	return cr_node;
}

NODE insert_beg(NODE first, int ele){
	
	NODE temp = getnode();
	temp-> data =ele;
	
	if(first == NULL){
		first = temp;
	}
	else{
		temp->next = first;
		first = temp;
	}
	
	return first;
}


NODE insert_end(NODE first, int ele){

	NODE temp = getnode();
	temp->data = ele;
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



NODE concatenate(NODE first1, NODE first2){
	NODE temp;
	temp = first1;
	
	if(first1 == NULL){
		return first2;
	}
	else if(first2 == NULL){
		return first1;
	}
	else{
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = first2;
		return first1;
	}
}


NODE display(NODE first){
	NODE temp = first;
	
	if(first == NULL){
		printf("LIST EMPTY\n");
		return first;
	}
	
	while(temp->next != NULL){
		printf("%d  ", temp->data);
		temp = temp->next;
	}
	printf("%d\n", temp->data);
	
	return first;
}


NODE sort_list(NODE first){
	int swapped = 0;
	NODE lptr = NULL;
	int temp;
	NODE curr;
	
	
	do{
		curr = first;
		//printf("IN DO WHILE");
		swapped = 0;
		while(curr->next != lptr){
			if(curr->data > (curr->next)->data){
				//printf("IN WHILE");
				temp = curr->data;
				curr->data = curr->next->data;
				curr->next->data = temp;
				swapped = 1;
			}
			curr = curr->next;
		}
		lptr = curr;
	}while(swapped == 1);
	
	return first;
}






