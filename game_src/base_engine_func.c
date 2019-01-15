/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** base_engine_func
*/

#include <math.h>
#include "data_structure/OmHash.h"
#include "OmEngine.h"

OmWindowS OmEngine_Init(void)
{
    OmWindowS new_window;

    new_window.window = sfRenderWindow_create((sfVideoMode){1280, 768, 32}, "Name", sfClose, NULL);
    new_window.clock = sfClock_create();
    new_window.window_size = (sfVector2u){1280, 768};
    new_window.window_style = sfClose;
    new_window.renderer = 0;
    new_window.renderer_frequency = 16.0;
    return (new_window);
}

struct OmEvent_Storage OmEngine_InitEvent(void)
{
    struct OmEvent_Storage events;

    for (int i = 0; i < sfEvtCount; i++) {
        for (int j = 0; j < sfKeyCount; j++) {
            events.data[i][j].callback = 0;
            events.data[i][j].data = 0;
        }
    }
    return (events);
}