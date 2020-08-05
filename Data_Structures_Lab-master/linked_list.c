#include<stdio.h>
#include<stdlib.h>

struct node{
	int val;
	struct node *next;
};

typedef struct node* NODE; 

NODE getnode();
NODE insert_beg(NODE first, int ele);
NODE insert_end(NODE first, int ele);
NODE display(NODE first);
NODE insert_any_pos(NODE first, int ele, int pos);
NODE delete_first(NODE first);
NODE delete_end(NODE first);
NODE delete_any_pos(NODE first, int pos);

void main(){
	
	int choice, ele, pos;
	NODE first = NULL;
	
	
	do{
		printf("1. Insert at the front. \n2. Insert at end. \n3. Display. \n4. Insert at any pos. \n5. Delete from FIRST \n6. DElete END \n7. Exit. \n8. Delete Any pos\n");
		scanf("%d", &choice);
		
		switch(choice){
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
		}
	}while(choice !=7);
}

NODE getnode(){
	NODE cr_node = (NODE)malloc(sizeof(struct node));
	cr_node->next = NULL;
	return cr_node;
}

NODE insert_beg(NODE first, int ele){
	
	NODE temp = getnode();
	temp-> val =ele;
	
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

NODE insert_any_pos(NODE first, int ele, int pos){
	
	NODE temp = getnode();
	temp->val = ele;
	NODE curr = first;
	NODE prev = first;
	int count = 1;
	
	if(first == NULL){
		first = temp;
	}
	else{
		while(count < pos && curr != NULL){
			prev = curr;
			curr = curr->next;
			count++;
		}
		prev->next = temp;
		temp->next = curr;
		
	}
	return first;
}

NODE delete_first(NODE first){
	
	if(first == NULL){
		printf("LIST EMPTY\n");
		return first;
	}
	
	else{
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
		printf("LIST EMPTY\n");
		return first;
	}
	
	while(temp->next != NULL){
		printf("%d\n", temp->val);
		temp = temp->next;
	}
	printf("%d\n", temp->val);
	
	return first;
}

NODE delete_end(NODE first){
	
	NODE temp, prev;
	prev = first;
	temp =first;
	int flag =0;
	
	if(first == NULL){
		printf("LIST EMPTY\n");
		return first;
	}
	else{
		while(temp->next != NULL){
			flag =1;
			prev = temp;
			temp = temp->next;			
		}
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

NODE delete_any_pos(NODE first, int pos){
	
	NODE temp = first;
	NODE prev = first;
	int count = 1;
	
	if(first == NULL){
		printf("LIST EMPTY\n");
	}
	else if(pos == 1){
		first = first->next;
		free(prev);
		return first;
	}
	else{
		while(count<pos && temp->next!=NULL){
			prev= temp;
			temp = temp->next;
			count++;
		}
		prev->next = temp->next;
		free(temp);
		return first;
	}
	
}
