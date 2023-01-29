#include <stdio.h>
#include <stdlib.h>
#include "langton.h"
#include "visualiser.h"
#include <string.h>

int main(int argc, char const *argv[]) {
    struct ant *ant = malloc(sizeof(struct ant));
    struct rule rule;

    if (argc > 2) {
        printf("Too many arguments supplied\n");
    }

    if (argc > 1) {
    rule.rules = (char*)malloc(sizeof(char) * sizeof(argv[1]));
    strcpy(rule.rules, argv[1]);

    for (int i = 0; i < strlen(rule.rules); i++) {
    if (rule.rules[i] != 'L' && rule.rules[i] != 'R') {
        printf("Invalid input for the rule\n");
        }
    }
    }
    
    start_visualisation(ant);
    if (argc > 1) {
        while (not_quit()) {
        ADVANCED_visualise_and_advance(ant, &rule);
        }
    } else {
        while (not_quit()) {
        visualise_and_advance(ant);
        }
    }
    end_visualisation();
    free(rule.rules);
}
