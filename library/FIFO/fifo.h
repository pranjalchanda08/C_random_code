/**
 * @file    fifo.h
 * @author  Pranjal Chanda (pranjalchanda08@gmail.com)
 * @brief   Linear Queue Library for any Data Type / Data Structure in C
 * @version 0.1
 * @date    2022-05-21
 *
 * Copyright (c) 2019-2022 Open License
 *
 */

#ifndef _FIFO_H_
#define _FIFO_H_

#include <string.h>

#define CONCAT_2(a, b) a##b
#define CONCAT_3(a, b, c) a##b##c

typedef enum fifo_err
{
    FIFO_SUCCESS,
    FIFO_FAILURE
} fifo_ret_t;

typedef struct cq
{
    char *p_buffer;
    size_t size;
    size_t element_size;
    size_t head;
    size_t tail;
} fifo_t;

#define FIFO_INIT_BUFFER(_NAME, _size, _type)                               \
    static char CONCAT_2(_NAME, _fifo_buffer)[(_size * sizeof(_type)) + 1]; \
    static fifo_t CONCAT_3(fifo_, _NAME, _inst) =                           \
        {                                                                   \
            .p_buffer = CONCAT_2(_NAME, _fifo_buffer),                      \
            .size = (_size * sizeof(_type)),                                \
            .element_size = sizeof(_type),                                  \
            .head = -1,                                                     \
            .tail = -1};

#define FIFO_INSTANCE(_NAME) CONCAT_3(fifo_, _NAME, _inst)

/**
 * @brief Enqueue Element to the Queue back
 *
 * @param p_fifo            Pointer to FIFO instance
 * @param p_element         Pointer to element to be enqued
 * @return fifo_ret_t       FIFO_SUCCESS or FIFO_FAILURE
 */
fifo_ret_t fifo_enqueue(fifo_t *p_fifo, char *p_element);

/**
 * @brief Dequeue Element from Queue Front
 *
 * @param p_fifo            Pointer to FIFO instance
 * @param p_element         Pointer to fetch dequed element
 * @return fifo_ret_t       FIFO_SUCCESS or FIFO_FAILURE
 */
fifo_ret_t fifo_dequeue(fifo_t *p_fifo, char *p_element);

/**
 * @brief Peak Queue Next Available element
 *
 * @param p_fifo            Pointer to FIFO instance
 * @param p_element         Pointer to element to to peak
 * @return fifo_ret_t       FIFO_SUCCESS or FIFO_FAILURE
 */
fifo_ret_t fifo_peak(fifo_t *p_fifo, char *p_element);

/**
 * @brief Returns the pointer to the element at the front
 *
 * @param p_fifo            Pointer to FIFO instance
 * @param p_element         Pointer to element returned
 * @return fifo_ret_t       FIFO_SUCCESS or FIFO_FAILURE
 */
fifo_ret_t fifo_front(fifo_t *p_fifo, char *p_element);

/**
 * @brief Returns the pointer to the element at the back
 *
 * @param p_fifo            Pointer to FIFO instance
 * @param p_element         Pointer to element returned
 * @return fifo_ret_t       FIFO_SUCCESS or FIFO_FAILURE
 */
fifo_ret_t fifo_back(fifo_t *p_fifo, char *p_element);

#endif /* _FIFO_H_ */