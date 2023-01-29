#include "langton.h"
#include "visualiser.h"
#include <ncurses.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

void turn_left(struct ant *ant) {
    if (ant->direction == UP) {
        ant->direction = LEFT;
    } else if (ant->direction == LEFT) {
        ant->direction = DOWN;
    } else if (ant->direction == DOWN) {
        ant->direction = RIGHT;
    } else if (ant->direction == RIGHT) {
        ant->direction = UP;
    }
}

void turn_right(struct ant *ant) {
    if (ant->direction == UP) {
        ant->direction = RIGHT;
    } else if (ant->direction == LEFT) {
        ant->direction = UP;
    } else if (ant->direction == DOWN) {
        ant->direction = LEFT;
    } else if (ant->direction == RIGHT) {
        ant->direction = DOWN;
    }
}

void move_forward(struct ant *ant) {
    if (ant->direction == UP) {
        ant->y =  ant->y - 1;
    } else if (ant->direction == LEFT) {
        ant->x =  ant->x - 1;
    } else if (ant->direction == DOWN) {
        ant->y =  ant->y + 1;
    } else if (ant->direction == RIGHT) {
        ant->x =  ant->x + 1;
    }
}

void apply_rule(enum colour *colour, struct ant *ant) {
    if (*colour == WHITE) {
        turn_right(ant);
        *colour = BLACK;
    } else if (*colour == BLACK) {
        turn_left(ant);
        *colour = WHITE;
    }
}

void apply_rule_general(enum colour *colour, struct ant *ant, struct rule *rule) {
    if (rule->rules[*colour] == 'L') {
      turn_left(ant);
    } else if (rule->rules[*colour] == 'R') {
        turn_right(ant);
    }
    if (strlen(rule->rules) == (*colour + 1)) {
        *colour = 0;
    } else {
        *colour = *colour + 1;
    }
}
