#ifndef _CQ_H_
#define _CQ_H_

#include <inttypes.h>
#include <string.h>

#define CONCAT_2(a, b) a##b
#define CONCAT_3(a, b, c) a##b##c

#define CQ_SUCCESS 0U
#define CQ_FAILURE 1U

typedef struct cq
{
    uint8_t *p_buffer;
    size_t size;
    size_t element_size;
    size_t head;
    size_t tail;
} cq_t;

#define CQ_INIT_BUFFER(_NAME, _size, _type)                                  \
    static uint8_t CONCAT_2(_NAME, _cq_buffer)[(_size * sizeof(_type)) + 1]; \
    static cq_t CONCAT_3(cq_, _NAME, _inst) =                                \
        {                                                                    \
            .p_buffer = CONCAT_2(_NAME, _cq_buffer),                         \
            .size = (_size * sizeof(_type)),                                 \
            .element_size = sizeof(_type),                                   \
            .head = 0,                                                       \
            .tail = -1};

#define CQ_INSTANCE(_NAME) CONCAT_3(cq_, _NAME, _inst)

int cq_enqueue(cq_t *p_cq, uint8_t *p_element);
int cq_dequeue(cq_t *p_cq, uint8_t *p_element);
int cq_peak(cq_t *p_cq, uint8_t *p_element);

#endif