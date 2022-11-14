
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct dll_node
{
  int data;
  struct dll_node *prev;
  struct dll_node *next;
}dll_node_t;

int d_linkedlist_lenght(dll_node_t *head);
void d_linkedlist_print_list(dll_node_t *head);
void d_linkedlist_insert_at_start(dll_node_t **head , int data);
void d_linkedlist_insert_at_end(dll_node_t **head , int data);
void d_linkedlist_insert_at_position(dll_node_t **head , int data , int position);
void d_linkedlist_delete_last_node(dll_node_t **head);
void d_linkedlist_delete_front_node(dll_node_t **head);
void d_linkedlist_delete_position_node(dll_node_t **head , int position);
