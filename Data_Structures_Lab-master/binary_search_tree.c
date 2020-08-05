#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int value;
    struct Node *leftChild;
    struct Node *rightChild;
};
typedef struct Node * node;

node getNode(int item){
    node temp;
    temp = (node)malloc(sizeof(struct Node));
    temp->value = item;
    temp->leftChild = NULL;
    temp->rightChild = NULL;
    return temp;
}

node insert(node root , int item){
    node curr , temp;
    temp = getNode(item);
    if(root == NULL){
        root = temp;
        return root;
    }
    else{
          if(item < root->value){
            root->leftChild = insert(root->leftChild , item);
          }
          else if(item >= root->value){
            root->rightChild = insert(root->rightChild , item);
          }
          return root;
    }
}

int checkRoot(node root){
    if(root == NULL){
        printf("\nRoot is Null\n");
        return 0;
    }
    else{
        return 1;
    }
}

void inorder(node root){
    if(root == NULL){
        return;
    }
    inorder(root->leftChild);
    printf("%d " , root->value);
    inorder(root->rightChild);
}

void preorder(node root){
    if(root == NULL){
        return;
    }
    printf("%d " , root->value);
    preorder(root->leftChild);
    preorder(root->rightChild);
}

void postorder(node root){
    if(root == NULL){
        return;
    }
    preorder(root->leftChild);
    preorder(root->rightChild);   
    printf("%d " , root->value);
}

int search(node root , int item){
    while(root != NULL){
        if(item > root->value){
            root = root->rightChild;
        }
        else if(item < root->value){
            root = root->leftChild;
        }
        else{
            return 1;
        }
    }
    return 0;
}

int main()
{
    int ch , item , n ;
    node root = NULL;
    printf("Enter the number of elements in binary tree : ");
    scanf("%d", &n);
    int ele[n];
    printf("\nEnter elements of Binary Tree\n");
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&ele[i]);
    }
    while(ch != 6)
    {
        printf("\n\n1.Form Binary search tree\n2.Inorder list\n3.Preorder list\n4.Postorder list\n5.Search an element\n6.Exit\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1 : for(int i = 0 ; i < n ; i++){
                       root = insert(root , ele[i]);
                     }
                     printf("\nBinary Search Tree formed\n");
                     break;
            case 2 : if(checkRoot(root) == 1){
                       printf("\n\nInorder list : ");
                       inorder(root);
                     }
                     break;
            case 3 : if(checkRoot(root) == 1){
                       printf("\n\nPreorder list : ");
                       preorder(root);
                     }
                     break; 
            case 4 : if(checkRoot(root) == 1){
                       printf("\n\nPostorder list : ");
                       postorder(root);
                     }
                     break;
            case 5 : printf("\n\nEnter item to be searched : ");
			         scanf("%d", &item);
				     if(search(root,item) == 1)
				    	printf("\nItem found\n");
			         else
					    printf("\nItem not found\n");
				     break;
			default : printf("\nInvalid choice\n");
			          break;
        }
    }
}