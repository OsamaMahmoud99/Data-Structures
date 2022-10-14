
#include "Arrays.h"


int main()
{
    array_t signal = {{10,11,12,14,15,16,17},50,7};
    array_t signal2 = {{11,21,31,11,11,13,14},50,7};

    array_t *full_signal;
    full_signal = array_merge(&signal , &signal2);

    for(int i=0; i<signal.length; ++i)
    {
        printf("%d ", signal.data[i]);
    }
    printf("\n---------------------\n");

    array_append(&signal , 1000);

    for(int i=0; i<signal.length; ++i)
    {
        printf("%d ", signal.data[i]);
    }

    array_insert(&signal , 2 , 4000);

    printf("\n---------------------\n");

    for(int i=0; i<signal.length; ++i)
    {
        printf("%d ", signal.data[i]);
    }

    array_delete(&signal , 3);
    printf("\n---------------------\n");

    for(int i=0; i<signal.length; ++i)
    {
        printf("%d ", signal.data[i]);
    }


    array_reverse(&signal);
    printf("\n---------------------\n");

    for(int i=0; i<signal.length; ++i)
    {
        printf("%d ", signal.data[i]);
    }

    array_sort_descend(&signal);
    printf("\n---------------------\n");

    for(int i=0; i<signal.length; ++i)
    {
        printf("%d ", signal.data[i]);
    }
    
    printf("\n---------------------\n");

    for(int i=0; i<full_signal->length; ++i)
    {
        printf("%d ", full_signal->data[i]);
    }

    return 0;
}

void array_append(array_t *array , int32_t element)
{
    if(array->length < array->size)
    {
        array->data[array->length++] = element;
    }
}

void array_insert(array_t *array , uint32_t indx , int32_t element)
{
    if(indx <= array->length)
    {
        for(int i=array->length; i>indx; --i)
        {
            array->data[i] = array->data[i-1];
        }
    }
    array->data[indx] = element;
    array->length++;
}

int32_t array_delete(array_t *array , uint32_t indx)
{
    int32_t element;
    if(indx < array->length)
    {
        element = array->data[indx];

        for(int i=indx; i<array->length-1; ++i)
        {
            array->data[i] = array->data[i+1];
        }
     array->length--;
     return element;
    }
    return 0;
}

void array_reverse(array_t *array)
{
    int i,j;
    int32_t *temp;

    temp = (int32_t*)malloc(array->length*sizeof(int32_t));

    for(i=array->length-1,j=0 ;i>=0; i--,j++)
    {
        temp[j] = array->data[i];
    }

    for(i=0; i<array->length; ++i)
    {
        array->data[i] = temp[i];
    }
}

int8_t array_isAscending(array_t *array)
{
    for(int i=0; i<array->length-1; ++i)
    {
        if(array->data[i] > array->data[i+1]){
            return 0;
        }
    }

    return 1;
}

int8_t array_isDescending(array_t *array)
{
    for(int i=0; i<array->length-1; ++i)
    {
        if(array->data[i] < array->data[i+1]){
            return 0;
        }
    }

    return 1;
}

void array_sort_ascend(array_t *array)
{
    int32_t i , j , temp;

    for(i=1; i<array->length; ++i)
    {
        temp = array->data[i];
        j = i;

        while(j>0 && temp < array->data[j-1]){
            array->data[j] = array->data[j-1];
            --j;
        }
        array->data[j] = temp;
    }
}

void array_sort_descend(array_t *array)
{
    int32_t i , j , temp;

    for(i=1; i<array->length; ++i)
    {
        temp = array->data[i];
        j = i;

        while(j>0 && temp > array->data[j-1]){
            array->data[j] = array->data[j-1];
            --j;
        }
        array->data[j] = temp;
    }
}

int32_t array_max(array_t *array)
{
    int32_t max = array->data[0];

    for(int i=0; i<array->length; ++i)
    {
        if(array->data[i] > max){
            max = array->data[i];
        }
    }

    return max;
}

int32_t array_min(array_t *array)
{
    int32_t min = array->data[0];

    for(int i=0; i<array->length; ++i)
    {
        if(array->data[i] < min){
            min = array->data[i];
        }
    }

    return min;
}

int32_t array_sum(array_t *array)
{
    int32_t sum = 0;

    for(int i=0; i<array->length; ++i)
    {
        sum += array->data[i];
    }

    return sum;
}

array_t * array_merge(array_t *array1 , array_t *array2)
{

    int32_t i=0,j=0,k=0;

    array_t *dest_arr = (array_t*)malloc(sizeof(array_t));

    while(i < array1->length && j < array2->length)
    {
        if(array1->data[i] < array2->data[j])
        {
            dest_arr->data[k++] = array1->data[i++];
        }
        else
        {
            dest_arr->data[k++] = array2->data[j++];
        }
    }

    for(;i<array1->length;++i)
    {
        dest_arr->data[k++] = array1->data[i];
    }
    for(;j<array2->length;++j)
    {
        dest_arr->data[k++] = array2->data[j];
    }
    dest_arr->length = array1->length + array2->length;

    return dest_arr;
}


