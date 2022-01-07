#include <curses.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "ui.h"

WINDOW *mainWindow = NULL;

int color_map[MAX_H+1] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 5, 5, 6};

void set_colors() {
    for (int i=0; i<8; i++) {
        init_pair(i+1, i, 0);
    }

    for (int i=0; i<6; i++) {
        init_color(i, 0, i*200, 0);
    }
    init_color(6, 200, 1000, 200);
}

void setup_colors() {
    if (has_colors()) {
        start_color();
        // use_default_colors();
        set_colors();
    } else {
        clear_ui();
        fprintf(stderr, "ERROR: Your terminal cant handle colors");
        exit(1);
    }
}

void init_ncurses() {
    if ((mainWindow = initscr()) == NULL) {
        fprintf(stderr, "Error in initscr()\n");
        exit(1);
    }
    cbreak();
    curs_set(0);
    setup_colors();
}

void draw_matrix() {
    for (int x=0; x<MAX_X; x++) {
        for (int y=0; y<MAX_Y; y++) {
            color_set(color_map[matrix[x][y].strength] , NULL);
            mvaddch(y, x, matrix[x][y].value);
        }
    }
    refresh();
}

void clear_ui() {
    delwin(mainWindow);
    endwin();
}

