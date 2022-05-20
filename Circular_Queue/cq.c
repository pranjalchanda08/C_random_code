#include "cq.h"

int cq_enqueue(cq_t * p_cq, uint8_t * p_element)
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
        if (p_cq->tail == (size_t)-1)   // First Element
        {
            p_cq->tail = 0;
        }
        else
        {
            p_cq->tail += p_cq->element_size;
        }
        p_cq->tail %= p_cq->size;
    }
    memcpy(p_cq->p_buffer + p_cq->tail, p_element, p_cq->element_size);
    
    return CQ_SUCCESS;
}
int cq_dequeue(cq_t *p_cq, uint8_t *p_element)
{
    memcpy(p_element, p_cq->p_buffer + p_cq->tail, p_cq->element_size);
    if (p_cq->head == p_cq->tail)
    {
        /* Queue Empty */
        return CQ_FAILURE;
    }
    else
    {
        p_cq->tail -= p_cq->element_size;
        p_cq->tail %= p_cq->size;
    }
    return CQ_SUCCESS;
}
int cq_peak(cq_t *p_cq, uint8_t *p_element)
{
    if (p_cq->head == p_cq->tail)
    {
        /* Queue Empty */
        return CQ_FAILURE;
    }
    memcpy(p_element, p_cq->p_buffer + p_cq->tail, p_cq->element_size);
    return CQ_SUCCESS;
}
