/*
** EPITECH PROJECT, 2018
** Engine
** File description:
** intern_hmap
*/

#include <string.h>
#include "data_structure/data_internal/OmHash_Internal.h"

bool intern_OmHash_find_key(char *to_find, char *src, size_t idx)
{
    (void)(idx);
    return ((src != 0 && strcmp(to_find, src) == 0));
}