/**
 * @file    cq.h
 * @author  Pranjal Chanda (pranjalchanda08@gmail.com)
 * @brief   Circular Queue Library for any Data Type / Data Structure in C
 * @version 0.1
 * @date    2022-05-21
 *
 * Copyright (c) 2019-2022 Open License
 * 
 */

#ifndef _CQ_H_
#define _CQ_H_

#include <string.h>

#define CONCAT_2(a, b)          a##b
#define CONCAT_3(a, b, c)       a##b##c

typedef enum cq_err {
    CQ_SUCCESS,
    CQ_FAILURE
} cq_ret_t;

typedef struct cq
{
    char  *p_buffer;
    size_t size;
    size_t element_size;
    size_t head;
    size_t tail;
} cq_t;

#define CQ_INIT_BUFFER(_NAME, _size, _type)                                  \
    static char CONCAT_2(_NAME, _cq_buffer)[(_size * sizeof(_type)) + 1];    \
    static cq_t CONCAT_3(cq_, _NAME, _inst) =                                \
        {                                                                    \
            .p_buffer = CONCAT_2(_NAME, _cq_buffer),                         \
            .size = (_size * sizeof(_type)),                                 \
            .element_size = sizeof(_type),                                   \
            .head = -1,                                                      \
            .tail = -1};

#define CQ_INSTANCE(_NAME) CONCAT_3(cq_, _NAME, _inst)

/**
 * @brief Enqueue Element to the Queue back
 * 
 * @param p_cq          Pointer to CQ instance 
 * @param p_element     Pointer to element to be enqued
 * @return cq_ret_t     CQ_SUCCESS or CQ_FAILURE 
 */
cq_ret_t cq_enqueue(cq_t *p_cq, char *p_element);

/**
 * @brief Dequeue Element from Queue Front
 * 
 * @param p_cq          Pointer to CQ instance 
 * @param p_element     Pointer to fetch dequed element
 * @return cq_ret_t     CQ_SUCCESS or CQ_FAILURE 
 */
cq_ret_t cq_dequeue(cq_t *p_cq, char *p_element);

/**
 * @brief Peak Queue Next Available element
 * 
 * @param p_cq          Pointer to CQ instance 
 * @param p_element     Pointer to element to to peak
 * @return cq_ret_t     CQ_SUCCESS or CQ_FAILURE 
 */
cq_ret_t cq_peak(cq_t *p_cq, char *p_element);

/**
 * @brief Returns the pointer to the element at the front
 * 
 * @param p_cq          Pointer to CQ instance 
 * @param p_element     Pointer to element returned
 * @return cq_ret_t     CQ_SUCCESS or CQ_FAILURE 
 */
cq_ret_t cq_front(cq_t *p_cq, char *p_element);

/**
 * @brief Returns the pointer to the element at the back
 *
 * @param p_cq          Pointer to CQ instance
 * @param p_element     Pointer to element returned
 * @return cq_ret_t     CQ_SUCCESS or CQ_FAILURE
 */
cq_ret_t cq_back(cq_t *p_cq, char *p_element);

#endif /* _CQ_H_ */