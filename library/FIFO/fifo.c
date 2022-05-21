/**
 * @file    fifo.c
 * @author  Pranjal Chanda (pranjalchanda08@gmail.com)
 * @brief   Definations of all Linear Queue Implementation
 * @version 0.1
 * @date    2022-05-21
 *
 * Copyright (c) 2019-2022 Open License
 *
 */
#include "fifo.h"

#define FIFO_ASSERT(cond)        \
    {                            \
        if (!(cond))             \
            ;                    \
        else                     \
            return FIFO_FAILURE; \
    }

fifo_ret_t fifo_enqueue(fifo_t *p_fifo, char *p_element)
{

    if ((p_fifo->tail + p_fifo->element_size) % p_fifo->size == p_fifo->head) // condition to check queue is full
    {
        return FIFO_FAILURE;
    }
    else
    {
        if (p_fifo->tail == (size_t)-1) // First Element
        {
            p_fifo->tail = p_fifo->head = 0;
        }
        else if (p_fifo->tail == p_fifo->size - p_fifo->element_size && p_fifo->head != 0)
        {
            p_fifo->tail = 0;
        }
        else
        {
            p_fifo->tail += p_fifo->element_size;
        }
    }
    memcpy(p_fifo->p_buffer + p_fifo->tail, p_element, p_fifo->element_size);

    return FIFO_SUCCESS;
}

fifo_ret_t fifo_dequeue(fifo_t *p_fifo, char *p_element)
{
    FIFO_ASSERT(p_fifo->tail == (size_t)-1);
    memcpy(p_element, p_fifo->p_buffer + p_fifo->head, p_fifo->element_size);
    if (p_fifo->head == p_fifo->tail)
    {
        p_fifo->head = p_fifo->tail = (size_t)-1;
        memset(p_fifo->p_buffer, 0, p_fifo->size);
    }
    else
    {
        p_fifo->head = p_fifo->head == p_fifo->size - p_fifo->element_size ? 0 : p_fifo->head + p_fifo->element_size;
    }

    return FIFO_SUCCESS;
}

fifo_ret_t fifo_peak(fifo_t *p_fifo, char *p_element)
{
    FIFO_ASSERT(p_fifo->head == (size_t)-1);
    memcpy(p_element, p_fifo->p_buffer + p_fifo->tail, p_fifo->element_size);
    return FIFO_SUCCESS;
}

fifo_ret_t fifo_front(fifo_t *p_fifo, char *p_element)
{
    FIFO_ASSERT(p_fifo->head == (size_t)-1);
    p_element = p_fifo->p_buffer + p_fifo->head;
    return FIFO_SUCCESS;
}

fifo_ret_t fifo_back(fifo_t *p_fifo, char *p_element)
{
    FIFO_ASSERT(p_fifo->head == (size_t)-1);
    p_element = p_fifo->p_buffer + p_fifo->tail;
    return FIFO_SUCCESS;
}