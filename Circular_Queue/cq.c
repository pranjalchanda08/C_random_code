#include "cq.h"

int cq_enqueue(cq_t *p_cq, char *p_element)
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
int cq_dequeue(cq_t *p_cq, char *p_element)
{
    if (p_cq->head == (size_t)-1)
    {
        return CQ_FAILURE;
    }
    memcpy(p_element, p_cq->p_buffer + p_cq->head, p_cq->element_size);
    if (p_cq->head == p_cq->tail)
    {
        p_cq->head = p_cq->tail = (size_t)-1;
    }
    else
    {
        p_cq->head = p_cq->head == p_cq->size - p_cq->element_size ? 0 : p_cq->head + p_cq->element_size;
    }

    return CQ_SUCCESS;
}
int cq_peak(cq_t *p_cq, char *p_element)
{
    if (p_cq->head == (size_t)-1)
    {
        /* Queue Empty */
        return CQ_FAILURE;
    }
    memcpy(p_element, p_cq->p_buffer + p_cq->tail, p_cq->element_size);
    return CQ_SUCCESS;
}

int cq_front(cq_t *p_cq, char *p_element)
{
    if (p_cq->head == (size_t)-1)
    {
        /* Queue Empty */
        return CQ_FAILURE;
    }
    p_element = p_cq->p_buffer + p_cq->head;
    return CQ_SUCCESS;
}

int cq_back(cq_t *p_cq, char *p_element)
{
    if (p_cq->tail == (size_t)-1)
    {
        /* Queue Empty */
        return CQ_FAILURE;
    }
    p_element = p_cq->p_buffer + p_cq->tail;
    return CQ_SUCCESS;
}