#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int size = 0;
struct node
{
  int data;
  struct node* next;
};

void push(struct node** headRef, int data)
{
  size++;
  struct node* head = *headRef;
  struct node* newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = NULL;
  if (head == NULL)
  {
    *headRef = newNode;
    printf("%d is pushed onto Stack\n", data);
    return;
  }
  newNode->next = head;
  *headRef = newNode;
  printf("%d is pushed onto Stack\n", data);
}
int isEmpty(struct node* head)
{
  return head == NULL;
}


int
     pop(struct node** headRef)
{
  if (isEmpty(*headRef))
  {
    printf("Stack underflow\n");
    return INT_MIN;
  }
  size--;
  struct node* head = *headRef;
  struct node* temp = head;
  head = head->next;
  int data = temp->data;
  free(temp);
  *headRef = head;
  return data;
}

int peek(struct node** headRef)
{
  struct node* head = *headRef;
  if (isEmpty(head))
  {
    return INT_MIN;
  }
  return head->data;
}

int sizeOfStack()
{
  return size;
}

int main()
{
  struct node* head = NULL;
  printf("size of the Stack = %d\n", sizeOfStack());
  push(&head, 5);
  push(&head, 7);
  push(&head, 2);
  printf("size of the Stack = %d\n", sizeOfStack());
  push(&head, 4);
  printf("size of the Stack = %d\n", sizeOfStack());
  printf("%d popped from the Stack\n", pop(&head));
  printf("%d is at the top of Stack\n", peek(&head));
  printf("size of the Stack = %d\n", sizeOfStack());
  printf("%d popped from the Stack\n", pop(&head));
  printf("%d popped from the Stack\n", pop(&head));
  printf("%d popped from the Stack\n", pop(&head));
  printf("size of the Stack = %d\n", sizeOfStack());
  printf("%d popped from the Stack\n", pop(&head));
  printf("size of the Stack = %d\n", sizeOfStack());
}