
#include <locale.h>
#include <stdlib.h>
#include <ncurses.h>
#include "visualiser.h"
#include "langton.h"

#define cell_under_ant cell_at(ant->y, ant->x)
cell *cells;

#define cell_at(y, x) (cells[x + (y * max_x)])

void start_visualisation(struct ant* ant) {
  setlocale(LC_ALL, "");

  initscr();
  curs_set(FALSE);
  max_x = getmaxx(stdscr);
  max_y = getmaxy(stdscr);
  cells = calloc(max_y*max_x, sizeof(cell));
  ant->x = max_x/2;
  ant->y = max_y/2;
  ant->direction = RIGHT;
}

void visualise_and_advance(struct ant* ant) {
  /* Draw cells and ant */
  for (int y=0; y < max_y; y++) {
    for (int x=0; x < max_x; x++) {
      mvprintw(y, x,
      ant_is_at(y, x)
        ? direction_to_s(ant->direction)
        : cell_at(y, x)
          ? "█"
          : " ");
         }
      }
      refresh();
      /* Advance to next step */
  apply_rule(&cell_under_ant, ant);
  // Implementation of the Torus
  if (ant->y == max_y - 1 && ant->direction == DOWN) {
    ant->y = 0;
  } else if (ant->y == 0 && ant->direction == UP) {
    ant->y = max_y -1;
  } else if (ant->x == 0 && ant->direction == LEFT) {
    ant->x = max_x - 1;
  } else if (ant->x == max_x - 1 && ant->direction == RIGHT) {
    ant->x = 0;
  } else if (true) {
    move_forward(ant);
  }
}

// Check if the user has input "q" to quit
bool not_quit() {
  return 'q' != getch();
}

void end_visualisation() {
  free(cells);
  endwin();
}

const char* direction_to_s(enum direction d) {
  return UP   == d ? "^" :
         DOWN == d ? "v" :
         LEFT == d ? "<" :
         /* else */  ">";
}

void ADVANCED_visualise_and_advance(struct ant* ant, struct rule* rule) {
  /* Draw cells and ant */
  for (int y=0; y < max_y; y++) {
    for (int x=0; x < max_x; x++) {
      mvprintw(y, x,
      (ant->y == y) && (ant->x == x)
        ? direction_to_s(ant->direction)
        :  "%c", (cell_at(y, x) % 95 + 33));
      }
      }
      refresh();
      /* Advance to next step */
  apply_rule_general(&cell_under_ant, ant, rule);
  // Implementation of the Torus
  if (ant->y == max_y - 1 && ant->direction == DOWN) {
    ant->y = 0;
  } else if (ant->y == 0 && ant->direction == UP) {
    ant->y = max_y - 1;
  } else if (ant->x == 0 && ant->direction == LEFT) {
    ant->x = max_x - 1;
  } else if (ant->x == max_x - 1 && ant->direction == RIGHT) {
    ant->x = 0;
  } else if (true) {
    move_forward(ant);
  }
}
