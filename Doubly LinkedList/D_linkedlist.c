
#include "D_linkedlist.h"

int main()
{
    dll_node_t *head = NULL;

    d_linkedlist_insert_at_start(&head , 10);
    d_linkedlist_insert_at_start(&head , 20);
    d_linkedlist_insert_at_start(&head , 40);
    d_linkedlist_insert_at_end(&head , 5);
    d_linkedlist_insert_at_position(&head , 15 , 3);
    d_linkedlist_insert_at_position(&head , 60 , 1);

    d_linkedlist_delete_front_node(&head);
    d_linkedlist_print_list(head);
    return 0;
}

int d_linkedlist_lenght(dll_node_t *head)
{
    dll_node_t *current = head;
    int count = 0;
    if(head == NULL){
        return 0;
    }
    while(current != NULL){
        current = current->next;
        count++;
    }

    return count;
}

void d_linkedlist_print_list(dll_node_t *head)
{
    dll_node_t *current = head;
    int count = 0;
    if(head == NULL){
        return 0;
    }
    while(current != NULL){
        printf("%d -->",current->data);
        current = current->next;
    }

}
void d_linkedlist_insert_at_start(dll_node_t **head , int data)
{
    dll_node_t *new_node = (dll_node_t*)malloc(sizeof(dll_node_t));

    if(!new_node){
        printf("Memory Error\n");
    }

    new_node->prev = NULL;
    new_node->data = data;
    new_node->next = NULL;

    if(*head == NULL){
        *head = new_node;
        return;
    }

    (*head)->prev = new_node;
    new_node->next = *head;
    *head = new_node;
}

void d_linkedlist_insert_at_end(dll_node_t **head , int data)
{

    dll_node_t *current = *head;
    dll_node_t *new_node = (dll_node_t*)malloc(sizeof(dll_node_t));

    if(!new_node){
        printf("Memory Error\n");
    }

    new_node->prev = NULL;
    new_node->data = data;
    new_node->next = NULL;

    if(*head == NULL){
        *head = new_node;
        return;
    }

    while(current->next!=NULL){
        current = current->next;
    }
    current->next = new_node;
    new_node->prev = current;
}

void d_linkedlist_insert_at_position(dll_node_t **head , int data , int position)
{
    int i = 1;
    dll_node_t *current = *head;
    dll_node_t *new_node = (dll_node_t*)malloc(sizeof(dll_node_t));

    if(!new_node){
        printf("Memory Error\n");
    }

    new_node->prev = NULL;
    new_node->data = data;
    new_node->next = NULL;

    if(position == 1)
    {
        new_node->next = *head;
        new_node->prev = NULL;

        if(*head){
            (*head)->prev = new_node;
        }

        *head = new_node;
        return;
    }

    while((i<position-1) && (current->next != NULL)){
        current = current->next;
        i++;
    }

    if(i<position-1){
        printf("Invalid position passed to function\n");
        return;
    }

    new_node->next = current->next;
    new_node->prev = current;

    if(current->next){
        current->next->prev = new_node;
    }

    current->next = new_node;
    return;

}

void d_linkedlist_delete_last_node(dll_node_t **head)
{
    dll_node_t *temp = *head;
    dll_node_t *current = *head;

    if(*head == NULL)
    {
        printf("the list is empty!!\r\n");
    }

    while(current->next != NULL)
    {
        current = current->next;
    }
    temp = current->prev;
    temp->next = current->next;
    free(current);
    return;
}

void d_linkedlist_delete_front_node(dll_node_t **head)
{
    dll_node_t *temp = *head;

    if(*head == NULL)
    {
        printf("the list is empty!!\r\n");
    }

    temp = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(temp);
    return;
}

void d_linkedlist_delete_position_node(dll_node_t **head , int position)
{
    dll_node_t *temp = *head;
    dll_node_t *current;
    int k = 1;

    if(*head == NULL)
    {
        printf("the list is empty!!\r\n");
    }

    if(position == 1)
    {
        *head = (*head)->next;

        if(*head != NULL)
        {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }

    while(k < position && temp->next != NULL)
    {
        temp = temp->next;
        k++;
    }
    if(k < position-1){
        printf("Invalid position passed to function\n");
        return;
    }

    current = temp->prev;
    current->next = temp->next;

    if(temp->next)
    {
        temp->next->prev = current;
    }
    free(temp);
    return;
}
