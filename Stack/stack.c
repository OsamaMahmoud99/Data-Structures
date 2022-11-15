
#include "stack.h"

int main()
{
    int capacity = 7;
    stack_t* temperature_values = stack_create(capacity);

    for(int i=0; i<=2*capacity; ++i)
    {
        stack_push(temperature_values , (i*5));
    }

    printf("Top element is %d\n\r",stack_top(temperature_values));
    printf("stack sie is %d\n\r",stack_getSize(temperature_values));

    printf("\r\n");

    for(int i=0; i<=2*capacity; ++i)
    {
        printf("stack popped element is : %d\r\n",stack_pop(temperature_values));
    }

    if(stack_isEmpty(temperature_values)){
        printf("stack is empty\r\n");
    }
    else{
        printf("stack is not empty\r\n");
    }
    return 0;
}

stack_t* stack_create(int capacity)
{
    stack_t* stack = malloc(sizeof(stack_t));

    if(stack == NULL)
    {
        printf("Not able to create stack of this size\r\n");
        return NULL;
    }

    stack->capacity = capacity;
    stack->top = -1;
    stack->array = malloc(stack->capacity * sizeof(int));
    if(!stack->array){
        printf("Not able to create stack of this size\r\n");
        return NULL;
    }

    return stack;
}

void stack_double_size(stack_t* stack)
{
    stack->capacity *=2;
    stack->array = realloc(stack->array , stack->capacity * sizeof(int));
}

int stack_isFull(stack_t* stack)
{
    return(stack->top == stack->capacity -1);
}

int stack_isEmpty(stack_t* stack)
{
    return(stack->top == -1);
}

int stack_getSize(stack_t* stack)
{
    return(stack->top +1);
}
void stack_push(stack_t* stack , int data)
{
    if(stack_isFull(stack)){
        stack_double_size(stack);
    }

    stack->array[++stack->top] = data;
}

int stack_pop(stack_t* stack)
{
    if(stack_isEmpty(stack)){
        printf("stack is empty\r\n");
        return -999;
    }

    return(stack->array[stack->top--]);
}

int stack_top(stack_t* stack)
{
    if(stack_isEmpty(stack)){
        printf("stack is empty\r\n");
        return -999;
    }
    return(stack->array[stack->top]);
}

void stack_delete(stack_t* stack)
{
    if(stack){
        if(stack->array){
            free(stack->array);
        }

        free(stack);
    }
}

void ll_stack_push(int data)
{
    node_t *newNode;

    newNode = (node_t*)malloc(sizeof(node_t));

    if(!newNode){
        printf("stack error \n\r");
    }
    else{
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }
}

int ll_stack_pop(void)
{
    node_t* temp;
    int popped_data = -999;
    if(top == NULL){
        printf("stack is empty\n\r");
        return popped_data;
    }
    else{
        temp = top;
        top = top->next;
        popped_data = temp->data;

        free(temp);
    }

    return popped_data;
}

void ll_stack_print(void)
{
    node_t* temp;
    temp = top;

    while(temp != NULL)
    {
        printf("The stack element is : %d\n\r",temp->data);
        temp = temp->next;
    }
    printf("\n\r");
}
