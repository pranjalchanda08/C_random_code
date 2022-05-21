#ifndef _CQ_H_
#define _CQ_H_

#include <inttypes.h>
#include <string.h>

#define CONCAT_2(a, b)          a##b
#define CONCAT_3(a, b, c)       a##b##c

#define CQ_SUCCESS              0U
#define CQ_FAILURE              1U

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
 * @return int          CQ_SUCCESS or CQ_FAILURE 
 */
int cq_enqueue(cq_t *p_cq, char *p_element);

/**
 * @brief Dequeue Element from Queue Front
 * 
 * @param p_cq          Pointer to CQ instance 
 * @param p_element     Pointer to fetch dequed element
 * @return int          CQ_SUCCESS or CQ_FAILURE 
 */
int cq_dequeue(cq_t *p_cq, char *p_element);

/**
 * @brief Peak Queue Next Available element
 * 
 * @param p_cq          Pointer to CQ instance 
 * @param p_element     Pointer to element to to peak
 * @return int          CQ_SUCCESS or CQ_FAILURE 
 */
int cq_peak(cq_t *p_cq, char *p_element);

/**
 * @brief Returns the pointer to the element at the front
 * 
 * @param p_cq          Pointer to CQ instance 
 * @param p_element     Pointer to element returned
 * @return int          CQ_SUCCESS or CQ_FAILURE 
 */
int cq_front(cq_t *p_cq, char *p_element);

/**
 * @brief Returns the pointer to the element at the back
 *
 * @param p_cq          Pointer to CQ instance
 * @param p_element     Pointer to element returned
 * @return int          CQ_SUCCESS or CQ_FAILURE
 */
int cq_back(cq_t *p_cq, char *p_element);
#endif