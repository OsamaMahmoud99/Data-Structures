#include "queue.h"

int main()
{
    queue_t* tempvalues;

    tempvalues = queue_create(5);

    queue_enqueue(tempvalues , 10);
    queue_enqueue(tempvalues ,30);
    queue_enqueue(tempvalues , 60);
    queue_enqueue(tempvalues , 100);

    printf("size is : %d\n",queue_getSize(tempvalues));
    printf("front element is : %d\n",queue_getFrontElem(tempvalues));

    queue_dequeue(tempvalues);
    printf("size is : %d\n",queue_getSize(tempvalues));

    return 0;
}

queue_t* queue_create(int capacity)
{
    queue_t* queue = malloc(sizeof(queue_t));

    if(!queue){
        printf("Memory error\n\r");
        return NULL;
    }
    queue->capacity = capacity;
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    queue->array = malloc(queue->capacity *sizeof(int));
    if(!queue->array){
        printf("Memory error\n\r");
        return NULL;
    }

    return queue;
}

int queue_getSize(queue_t* queue)
{
    return queue->size;
}

int queue_getFrontElem(queue_t* queue)
{
    return queue->array[queue->front];
}

int queue_getRearElem(queue_t* queue)
{
    return queue->array[queue->rear];
}

int queue_isEmpty(queue_t* queue)
{
    return (queue->size == 0);
}

int queue_isFull(queue_t* queue)
{
    return (queue->size == queue->capacity);
}

void queue_enqueue(queue_t* queue , int data)
{
    if(queue_isFull(queue)){
        printf("Queue is full\r\n");
    }
    else{
        queue->rear = (queue->rear+1)% queue->capacity;
        queue->array[queue->rear] = data;

        if(queue->front == -1){
            queue->front = queue->rear;
        }
        queue->size += 1;
    }
}

int queue_dequeue(queue_t* queue)
{
    int data = -999;
    if(queue_isEmpty(queue)){
        printf("Queue is Empty \r\n");
        return NULL;
    }

    data = queue->array[queue->front];
    if(queue->front == queue->rear){
        queue->front = queue->rear = -1;
        queue->size = 0;
    }
    else{
        queue->front = (queue->front)% queue->capacity;
        queue->size -= 1;
    }

    return data;
}

void queue_delete(queue_t* queue)
{
    if(queue){

        if(queue->array){
            free(queue->array);
        }
        free(queue);
    }
}
