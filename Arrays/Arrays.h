
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef struct array
{
    int32_t data[50];
    int32_t size;
    int32_t length;
}array_t;

void array_append(array_t *array , int32_t element);
void array_insert(array_t *array , uint32_t indx , int32_t element);
int32_t array_delete(array_t *array , uint32_t indx);
void array_reverse(array_t *array);
int8_t array_isAscending(array_t *array);
int8_t array_isDescending(array_t *array);
void array_sort_ascend(array_t *array);
void array_sort_descend(array_t *array);
int32_t array_max(array_t *array);
int32_t array_min(array_t *array);
int32_t array_sum(array_t *array);
array_t * array_merge(array_t *array1 , array_t *array2);