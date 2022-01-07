#ifndef __UI_H__
#define __UI_H__

#include <stdint.h>
#include <ncurses.h>

#define MAX_Y 51
#define MAX_X 191

#define MAX_H 13
#define MIN_H 2

typedef struct {
    char value;
    int8_t strength;
} cell;

extern cell matrix[MAX_X][MAX_Y];

void init_ncurses();

void draw_matrix();

void clear_ui();

#endif // __UI_H__

