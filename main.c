#include "matrix.h"
#include "ui.h"

#include <unistd.h>

// between 1 and 0
#define SPEED 0.5

#define DELAY 100000L
#define ITERATIONS 300

int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  init_ncurses();

  init_matrix();

  for (int i=0; i<ITERATIONS; i++) {
    update_matrix();
    draw_matrix();
    usleep(DELAY*SPEED);
    // getch();
  }

  clear_ui();

  return 0;
}

