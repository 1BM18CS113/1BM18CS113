#include <stdio.h> 
#include <stdlib.h> 
#include <inttypes.h> 


struct Node 
{ 
  int data; 
  struct Node* next; 
}; 


struct Node* XOR (struct Node *a, struct Node *b) 
{ 
  return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b)); 
} 


void insert(struct Node **head_ref, int data) 
{ 

  struct Node *new_node = (struct Node *) malloc (sizeof (struct Node) ); 
  new_node->data = data; 


  new_node->next = *head_ref; 

  if (*head_ref != NULL) 
  { 

      (*head_ref)->next = XOR(new_node, (*head_ref)->next); 
  } 


  *head_ref = new_node; 
} 



void insertEnd (struct Node *head, int data) 
{ 
  struct Node *new_node = (struct Node *) malloc (sizeof (struct Node) );
  new_node->data = data; 

  struct Node *curr = head; 
  struct Node *prev = NULL; 
  struct Node *next; 



  while (curr->next != NULL) 
  {   
      
      next = XOR (prev, curr->next); 

      
      prev = curr; 
      curr = next; 
  } 

  prev->next = XOR(new_node, (XOR(NULL, prev->next)));
  new_node->next = XOR(NULL, prev);
} 




void printList (struct Node *head) 
{ 
  struct Node *curr = head; 
  struct Node *prev = NULL; 
  struct Node *next; 



  while (curr != NULL) 
  {       
      next = XOR (prev, curr->next); 

      
      prev = curr; 
      curr = next; 
  } 
} 

// Driver program 
int main () 
{ 

  struct Node *head = NULL; 
  insert(&head, 10); 
  insert(&head, 20); 
  insert(&head, 30); 
  insert(&head, 40); 

  insertEnd(head, 100); 
  insertEnd(head, 200); 
  insertEnd(head, 300); 


  printList (head); 

  return (0); 
} 