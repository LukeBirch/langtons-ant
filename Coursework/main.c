#include <stdio.h>
#include <stdlib.h>
#include "langton.h"
#include "visualiser.h"


int main(int argc, char const *argv[])
{
    struct ant *ant;
    //ant = malloc(sizeof(struct ant));
    start_visualisation(&ant);
    /*
    while(true){
        char input = getchar();
        if(input == 'q'){
            end_visualisation();
        }
        visualise_and_advance(ant);
    }
    */
    // }
    //visualise_and_advance(&ant);
    while(not_quit()){
        visualise_and_advance(&ant);
    }
    end_visualisation();   
    //free(ant);

}