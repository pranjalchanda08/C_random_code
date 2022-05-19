#ifndef _CQ_H_
#define _CQ_H_

#define CONCAT_2(a,b)           a##b
#define CONCAT_3(a,b,c)         a##b##c

typedef struct cq_attr
{
    void *p_buffer;
    size_t size;
} cq_attr_t;

#define circular_queue_init(NAME, size, type)  \
    type CONCAT_2(NAME, _cq_buffer)[size + 1]; \
    cq_attr_t CONCAT_3(cq_, NAME, _attr);


#endif