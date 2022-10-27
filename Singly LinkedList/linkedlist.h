
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct node
{
  int data;
  struct node *next;

}node_t;

uint8_t linkedlist_create(int32_t *arr , int32_t arr_len);
uint32_t linkedlist_length(node_t *l_list);
uint8_t linkedlist_insert(node_t *l_list , uint32_t indx , int32_t element);
int32_t linkedlist_delete(node_t *l_list , uint32_t indx);
int32_t linkedlist_min(node_t *l_list);
int32_t linkedlist_max(node_t *l_list);
int32_t linkedlist_reverse(node_t *l_list);