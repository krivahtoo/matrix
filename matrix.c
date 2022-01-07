#include "matrix.h"
#include "ui.h"
#include <stdbool.h>
#include <stdlib.h>

#define DRIPS_COUNT 300
#define PROB_DRIP_SPAWN 0.65
#define PROB_DIM 0.3
#define PROB_CHANGE 0.85
#define RANDOM_CHAR (33 + (rand()%80))

typedef struct {
    int x, y;
    bool active;
} drip;

cell matrix[MAX_X][MAX_Y];
drip drips[DRIPS_COUNT];

double rand1() {
    return (double)rand() / (double)RAND_MAX;
}

void init_drips() {
    for (int i=0; i<DRIPS_COUNT; i++) {
        drips[i].active = false;
    }
}

void init_matrix() {
    for (int x=0; x<MAX_X; x++) {
        for (int y=0; y<MAX_Y; y++) {
            matrix[x][y].value = 0;
            matrix[x][y].strength = 0;
        }
    }
    init_drips();
}

void change_matrix() {
    for (int x=0; x<MAX_X; x++) {
        for (int y=0; y<MAX_Y; y++) {
            if (matrix[x][y].value == 0)
                matrix[x][y].value = RANDOM_CHAR;
            // randomly dim cells
            if (rand1() < PROB_DIM)
                if (matrix[x][y].strength > 0)
                    matrix[x][y].strength--;
        }
    }
}

void add_drips() {
    for (int i=0; i<DRIPS_COUNT; i++) {
        if (drips[i].active == false) {
            drips[i].active = true;
            drips[i].x = rand() % MAX_X;
            drips[i].y = 0;
            return;
        }
    }
}

void update_drips() {
    for (int i=0; i<DRIPS_COUNT; i++) {
        if (drips[i].active) {
            matrix[drips[i].x][drips[i].y].strength = MIN_H + (rand() % MAX_H);

            if (++drips[i].y >= MAX_Y) {
                drips[i].active = false;
            } else {
                matrix[drips[i].x][drips[i].y].value = RANDOM_CHAR;
            }
        } 
    }
}

void update_matrix() {
    if (rand1() < PROB_DRIP_SPAWN) {
        add_drips();
    }
    update_drips();

    change_matrix();
}

