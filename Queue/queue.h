#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


struct Queue
{
    int front;
    int rear;
    int capacity;
    int size;
    int* array;
};

typedef struct Queue queue_t;

queue_t* queue_create(int capacity);
int queue_getSize(queue_t* queue);
int queue_getFrontElem(queue_t* queue);
int queue_getRearElem(queue_t* queue);
int queue_isEmpty(queue_t* queue);
int queue_isFull(queue_t* queue);
void queue_enqueue(queue_t* queue , int data);
int queue_dequeue(queue_t* queue);
void queue_delete(queue_t* queue);