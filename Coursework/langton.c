#include "langton.h"
#include "visualiser.h"
#include <ncurses.h>
#include <locale.h>
/*
void start_visualisation(struct ant* ant) {
  setlocale(LC_ALL, "");

   initscr();
   curs_set(FALSE);
   max_x = getmaxx(stdscr);
   max_y = getmaxy(stdscr);
}
*/
void turn_left(struct ant *ant)
{
    if(ant->direction == UP){
        ant->direction = LEFT;
    }
    else if(ant->direction == LEFT){
        ant->direction = DOWN;
    }
    else if(ant->direction == DOWN){
        ant->direction = RIGHT;
    }
    else if(ant->direction == RIGHT){
        ant->direction = UP;
    }
};

void turn_right(struct ant *ant)
{
    if(ant->direction == UP){
        ant->direction = RIGHT;
    }
    else if(ant->direction == LEFT){
        ant->direction = UP;
    }
    else if(ant->direction == DOWN){
        ant->direction = LEFT;
    }
    else if(ant->direction == RIGHT){
        ant->direction = DOWN;
    }
};

void move_forward(struct ant *ant)
{
    if(ant->direction == UP){
        /*if(ant->y == 0 ){
        ant->y = max_y;
        }
        else{*/
            
        ant->y =  ant->y - 1;
       // }
    }
    else if(ant->direction == LEFT){
        /*
        if(ant->x == 0 ){
            ant->x = max_x;
        }
        else{*/
        ant->x =  ant->x - 1;
        //}
    }
    else if(ant->direction == DOWN){
        /*
        if(ant->y == max_y){
            ant->y = 0;
        }
        else {*/
        ant->y =  ant->y + 1;
        //}
    }
    else if(ant->direction == RIGHT){
        /*if(ant->x == max_x){
            ant->x = 0;
        }
        else {*/
        ant->x =  ant->x + 1;
        //}
    }
};

void apply_rule(enum colour *colour, struct ant *ant)
{
    if(*colour == WHITE){
        turn_right(ant);
        *colour = BLACK;
    }
    else if(*colour == BLACK){
        turn_left(ant);
        *colour = WHITE;
    }
};
