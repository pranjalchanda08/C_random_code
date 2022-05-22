#include "sort.h"

static void swap(char *x, char *y, char* dummy_buff, size_t element_size)
{
    memcpy(dummy_buff, x, element_size);
    memcpy(x, y, element_size);
    memcpy(y, dummy_buff, element_size);
}

void bubbleSort(sort_t *p_sort)
{
    size_t i, j;
    for (i = 0; i < (p_sort->size_buffer - p_sort->buffer_node_size); i += p_sort->buffer_node_size)
    {
        for (j = 0; j < (p_sort->size_buffer - p_sort->buffer_node_size - i); j += p_sort->buffer_node_size)
            if (memcmp((p_sort->p_buffer + j + p_sort->sort_param_offset),
                       (p_sort->p_buffer + j + p_sort->sort_param_offset + p_sort->buffer_node_size),
                       (p_sort->sort_param_size == 0 ? p_sort->buffer_node_size : p_sort->sort_param_size)) > 0)
            {
                swap(p_sort->p_buffer + j,
                     p_sort->p_buffer + j + p_sort->buffer_node_size,
                     p_sort->p_dummy_buff, p_sort->buffer_node_size);
            }
    }
        
    return;
}

void insertionSort(sort_t *p_sort)
{
    size_t i, j;
    for (i = p_sort->buffer_node_size; i < p_sort->size_buffer; i += p_sort->buffer_node_size)
    {
        memcpy(p_sort->p_dummy_buff, p_sort->p_buffer + i, p_sort->buffer_node_size); // key
        j = i - p_sort->buffer_node_size;
        while   ((j >= 0) &&
                (memcmp((p_sort->p_buffer + j + p_sort->sort_param_offset),
                        (p_sort->p_dummy_buff + p_sort->sort_param_offset),
                        (p_sort->sort_param_size == 0 ? p_sort->buffer_node_size : p_sort->sort_param_size)) > 0)
                )
        {
            memcpy(p_sort->p_buffer + j + p_sort->buffer_node_size,
                   p_sort->p_buffer + j,
                   p_sort->buffer_node_size);
            j = j - p_sort->buffer_node_size;
        }
        memcpy(p_sort->p_buffer + j + p_sort->buffer_node_size,
               p_sort->p_dummy_buff,
               p_sort->buffer_node_size);
    }
}