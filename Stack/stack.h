#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Stack
{
  int top;
  int capacity;
  int *array;
}stack_t;

stack_t* stack_create(int capacity);
void stack_double_size(stack_t* stack);
int stack_isFull(stack_t* stack);
int stack_isEmpty(stack_t* stack);
void stack_push(stack_t* stack , int data);
int stack_pop(stack_t* stack);
int stack_top(stack_t* stack);
void stack_delete(stack_t* stack);

struct Node
{
    int data;
    struct Node *next;
}*top=NULL;

typedef struct Node node_t;
void ll_stack_push(int data);
int ll_stack_pop(void);
void ll_stack_print(void);