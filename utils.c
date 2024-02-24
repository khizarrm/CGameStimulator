#include "defs.h"

//add error checking
void setPos(PositionType* position, int row, int col) {
    position->col = col;
    position->row = row;
}

//redo
void computeHeroDir(EscapeType* esc, FlyerType* flyer, int* col) {
    HeroArrayType heroes = esc->heroes;
    int numHeroes = esc->heroes.size;
    int smallestDistance = MAX_COL;

    for (int i = 0; i < numHeroes; ++i) {
        int distance = abs(heroes.elements[i]->partInfo.pos.col - flyer->partInfo.pos.col);
        if (distance < smallestDistance) {
            smallestDistance = distance;
        }
    }

    if (smallestDistance < 0) {
        *col = -1;
    } else {
        *col = 1;
    }
}


int randomIntRange(int min, int max) {
    return min + (rand() % (max - min + 1));
}

HeroType* checkForCollision(PositionType* position, EscapeType* escape) {
    for (int i = 0; i < escape->heroes.size; i++) {
        if (escape->heroes.elements[i] != NULL) {
            if (position->col == escape->heroes.elements[i]->partInfo.pos.col &&
                position->row == escape->heroes.elements[i]->partInfo.pos.row) {
                return escape->heroes.elements[i];
            }
        }
    }
    return NULL;
}

    

