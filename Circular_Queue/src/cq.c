/**
 * @file    cq.c
 * @author  Pranjal Chanda (pranjalchanda08@gmail.com)
 * @brief   Definations of all Circular Queue Implementation
 * @version 0.1
 * @date    2022-05-21
 *
 * Copyright (c) 2019-2022 Open License
 *
 */
#include "cq.h"

#define CQ_ASSERT(cond)        \
    {                          \
        if (!(cond))           \
            ;                  \
        else                   \
            return CQ_FAILURE; \
    }

cq_ret_t cq_enqueue(cq_t *p_cq, char *p_element)
{

    if ((p_cq->tail + p_cq->element_size) % p_cq->size == p_cq->head) // condition to check queue is full
    {
        p_cq->tail += p_cq->element_size;
        p_cq->tail %= p_cq->size;
        p_cq->head += p_cq->element_size;
        p_cq->head %= p_cq->size;
    }
    else
    {
        if (p_cq->tail == (size_t)-1) // First Element
        {
            p_cq->tail = p_cq->head = 0;
        }
        else if (p_cq->tail == p_cq->size - p_cq->element_size && p_cq->head != 0)
        {
            p_cq->tail = 0;
        }
        else
        {
            p_cq->tail += p_cq->element_size;
        }
    }
    memcpy(p_cq->p_buffer + p_cq->tail, p_element, p_cq->element_size);

    return CQ_SUCCESS;
}

cq_ret_t cq_dequeue(cq_t *p_cq, char *p_element)
{
    CQ_ASSERT(p_cq->head == (size_t)-1);
    memcpy(p_element, p_cq->p_buffer + p_cq->head, p_cq->element_size);
    if (p_cq->head == p_cq->tail)
    {
        p_cq->head = p_cq->tail = (size_t)-1;
        memset(p_cq->p_buffer, 0, p_cq->size);
    }
    else
    {
        p_cq->head = p_cq->head == p_cq->size - p_cq->element_size ? 0 : p_cq->head + p_cq->element_size;
    }

    return CQ_SUCCESS;
}

cq_ret_t cq_peak(cq_t *p_cq, char *p_element)
{
    CQ_ASSERT(p_cq->head == (size_t)-1);
    memcpy(p_element, p_cq->p_buffer + p_cq->tail, p_cq->element_size);
    return CQ_SUCCESS;
}

cq_ret_t cq_front(cq_t *p_cq, char *p_element)
{
    CQ_ASSERT(p_cq->head == (size_t)-1);
    p_element = p_cq->p_buffer + p_cq->head;
    return CQ_SUCCESS;
}

cq_ret_t cq_back(cq_t *p_cq, char *p_element)
{
    CQ_ASSERT(p_cq->head == (size_t)-1);
    p_element = p_cq->p_buffer + p_cq->tail;
    return CQ_SUCCESS;
}