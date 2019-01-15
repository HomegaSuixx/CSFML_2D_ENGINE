/*
** EPITECH PROJECT, 2018
** Engine
** File description:
** hmap_values
*/

#include <stdlib.h>
#include "data_structure/OmVector.h"
#include "data_structure/data_internal/OmHash_Internal.h"
#include "data_structure/OmHash.h"

static char *my_strdup(const char *s)
{
    int size = strlen(s);
    char *new = malloc(sizeof(char) * size + 1);

    if (!new)
        return (NULL);
    for (int i = 0; s[i]; i++)
        new[i] = s[i];
    new[size] = 0;
    return (new);
}

void *OmHash_get(OmHashS *this, char *key)
{
    ssize_t idx;

    if (this == 0)
        return (0);
    idx = OmVector.find_index(this->keys,
            (bool (*)(void *, void *, size_t))(intern_OmHash_find_key), key);
    return ((idx != 1) ? OmVector.at(this->data, idx) : 0);
}

bool OmHash_set(OmHashS *this, char *key, void *value)
{
    ssize_t idx;
    bool ret = true;

    if (this == 0)
        return (false);
    idx = OmVector.find_index(this->keys,
                (bool (*)(void *, void *, size_t))(intern_OmHash_find_key),
                key);
    if (idx == -1) {
        ret = ret && OmVector.push_back(this->keys, 1, my_strdup(key));
        ret = ret && OmVector.push_back(this->data, 1, value);
        this->size += ret;
        return (ret);
    }
    return (OmVector.set(this->data, idx, value));
}

void *OmHash_remove(OmHashS *this, char *key)
{
    ssize_t idx;

    if (this == 0)
        return (0);
    idx = OmVector.find_index(this->keys,
            (bool (*)(void *, void *, size_t))(intern_OmHash_find_key),
            key);
    if (idx == -1)
        return (0);
    this->size -= 1;
    free(OmVector.remove(this->keys, idx));
    return (OmVector.remove(this->data, idx));
}

bool OmHash_reserve(OmHashS *this, size_t capacity)
{
    bool ret = true;

    ret |= ret && (this != 0);
    ret |= ret && OmVector.reserve(this->keys, capacity);
    ret |= ret && OmVector.reserve(this->data, capacity);
    return (ret);
}

void OmHash_shrink_to_fit(OmHashS *this)
{
    if (this == 0)
        return;
    OmVector.shrink_to_fit(this->keys);
    OmVector.shrink_to_fit(this->data);
}