/**
 * @file sort.h
 * @author Pranjal Chanda (pranjalchanda08@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-05-21
 *
 * Copyright (c) 2019-2022 Open License
 *
 */
#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <string.h>
#include <stddef.h>

#define SORT_CONCAT_2(a, b) a##b
#define SORT_CONCAT_3(a, b, c) a##b##c

typedef struct sort
{
    char *p_buffer;
    char *p_dummy_buff;
    size_t buffer_node_size;
    size_t size_buffer;
    size_t sort_param_offset;
    size_t sort_param_size;
} sort_t;

#define SORT_INSTANCE_STRUCT(_NAME, _type, _buff, _sort_param_offset_var) \
    static _type SORT_CONCAT_3(sort_, _NAME, _dummy_buff)[sizeof(_type)]; \
    static sort_t SORT_CONCAT_3(sort_, _NAME, _inst) = {                  \
        .buffer_node_size = sizeof(_type),                                \
        .p_buffer = (char *)_buff,                                        \
        .size_buffer = sizeof(_buff),                                     \
        .sort_param_offset = offsetof(_type, _sort_param_offset_var),     \
        .sort_param_size = sizeof(((_type *)0)->_sort_param_offset_var),  \
        .p_dummy_buff = (char *)SORT_CONCAT_3(sort_, _NAME, _dummy_buff)};

#define SORT_INSTANCE_VAR(_NAME, _type, _buff)                           \
    static _type SORT_CONCAT_3(sort, _NAME, _dummy_buff)[sizeof(_type)]; \
    static sort_t SORT_CONCAT_3(sort_, _NAME, _inst) = {                 \
        .buffer_node_size = sizeof(_type),                               \
        .p_buffer = (char *)_buff,                                       \
        .size_buffer = sizeof(_buff),                                    \
        .sort_param_offset = 0,                                          \
        .sort_param_size = 0,                                            \
        .p_dummy_buff = (char *)SORT_CONCAT_3(sort_, _NAME, _dummy_buff)};

void bubbleSort(sort_t *p_sort);

#endif /*_SORT_H_*/