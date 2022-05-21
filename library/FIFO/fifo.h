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

#define FIFO_CONCAT_2(a, b) a##b
#define FIFO_CONCAT_3(a, b, c) a##b##c

typedef unsigned char u_char;

typedef enum fifo_err
{
    FIFO_SUCCESS,
    FIFO_FAILURE
} fifo_ret_t;

typedef struct cq
{
    char *p_buffer;
    const u_char is_circular : 1;
    size_t size;
    size_t element_size;
    size_t head;
    size_t tail;
} fifo_t;

#define FIFO_INIT_BUFFER_CIRCULAR(_NAME, _size, _type) FIFO_INIT_BUFFER(_NAME, _size, _type, 1)
#define FIFO_INIT_BUFFER_LINEAR(_NAME, _size, _type) FIFO_INIT_BUFFER(_NAME, _size, _type, 0)

#define FIFO_INIT_BUFFER(_NAME, _size, _type, _is_circular)                      \
    static char FIFO_CONCAT_2(_NAME, _fifo_buffer)[(_size * sizeof(_type)) + 1]; \
    static fifo_t FIFO_CONCAT_3(fifo_, _NAME, _inst) =                           \
        {                                                                        \
            .is_circular = _is_circular,                                         \
            .p_buffer = FIFO_CONCAT_2(_NAME, _fifo_buffer),                      \
            .size = (_size * sizeof(_type)),                                     \
            .element_size = sizeof(_type),                                       \
            .head = -1,                                                          \
            .tail = -1};

#define FIFO_INSTANCE(_NAME) FIFO_CONCAT_3(fifo_, _NAME, _inst)

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