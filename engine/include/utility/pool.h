/*
** EPITECH PROJECT, 2018
** CSFML_2D_RENDERER
** File description:
** pool
*/

#pragma once

#include <sys/types.h>

typedef struct OmPool {
    size_t max;
    ssize_t top;
    void **data;
} OmPoolS;

typedef struct {
    OmPoolS *(* const create)(size_t pool_size);
    void (* const destroy)(OmPoolS *handle);
    void (* const push)(OmPoolS *handle, void *data_ptr);
    void *(* const pop)(OmPoolS *handle, size_t idx);
    void (* const insert)(OmPoolS *handle, size_t idx, void *ptr_data);
    void (* const clear)(OmPoolS *handle);
} _OmPool;

extern _OmPool const OmPool;