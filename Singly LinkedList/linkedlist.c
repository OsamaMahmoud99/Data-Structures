
#include "linkedlist.h"

node_t *head;

int main()
{
   int32_t arr[]={1 , 2 , 3 , 4 , 5 , 6 , 7};
   linkedlist_create(arr , 7);

   //linkedlist_insert(head , 1 , 20);

  // linkedlist_delete(head , 5);

     linkedlist_reverse(head);

    while(head != NULL){
        printf("%d ",head->data);
        head = head->next;
    }

   // int32_t max = linkedlist_max(head);

    //printf("%d\n",max);

    free(head);

    return 0;
}

uint8_t linkedlist_create(int32_t *arr , int32_t arr_len)
{
    node_t *last , *temp;
    int i;

     head = (node_t*)malloc(sizeof(node_t));
    if(head == 0){
        return 0;
    }

    head->data = arr[0];
    head->next = NULL;
    last = head;

    for(i=1; i<arr_len; ++i)
    {
        temp = (node_t*)malloc(sizeof(node_t));
        if(temp == 0){
          return 0;
        }

        temp->data = arr[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }

    return 1;

}

uint32_t linkedlist_length(node_t *l_list)
{
    uint32_t len = 0;

    while(l_list)
    {
        len++;
        l_list = l_list->next;
    }
    return len;
}

uint8_t linkedlist_insert(node_t *l_list , uint32_t indx , int32_t element)
{
    node_t *temp;

    if(indx > linkedlist_length(l_list)){
        return 0;
    }

    temp = (node_t*)malloc(sizeof(node_t));
    temp->data = element;

    if(indx == 0){
        temp->next = l_list;
        l_list = temp;
    }
    else{

        for(int i=0; i<indx-1; ++i){
            l_list = l_list->next;
        }
        temp->next = l_list->next;
        l_list->next = temp;
    }

    return 1;
}

int32_t linkedlist_delete(node_t *l_list , uint32_t indx)
{
    node_t *temp;
    int32_t del;

    if(indx > linkedlist_length(l_list)){
        return 0;
    }

    if(indx == 1){
        temp = head;
        del = head->data;
        head = temp->next;
        free(temp);
        return del;
    }
    else{

        for(int i=0; i<indx-1; ++i){
            temp = l_list;
            l_list = l_list->next;
        }
        temp->next = l_list->next;
        del = l_list->data;
        free(l_list);
        return del;
    }
}

int32_t linkedlist_min(node_t *l_list)
{
    int32_t min = 1e9;

    while(l_list != NULL){

        if(l_list->data < min){
            min = l_list->data;
        }

        l_list = l_list->next;
    }

    return min;
}

int32_t linkedlist_max(node_t *l_list)
{
    int32_t max = -1e9;

    while(l_list != NULL){

        if(l_list->data > max){
            max = l_list->data;
        }

        l_list = l_list->next;
    }

    return max;
}

int32_t linkedlist_reverse(node_t *l_list)
{
    node_t *temp;
    int32_t *arr;

    temp = l_list;
    int i = 0;

    arr = (int32_t *)malloc(sizeof(int32_t)*linkedlist_length(l_list));

    if(arr == NULL){
        return 0;
    }

    while(temp != NULL){
        arr[i] = temp->data;
        temp = temp->next;
        i++;
    }

    temp = l_list;
    i--;

    while(temp != NULL){
        temp->data = arr[i];
        temp = temp->next;
        i--;
    }

    return 1;
}
