#include "defs.h"

void spawnFlyer(EscapeType* escape, char avatar, int strength, int row, int col) {
    FlyerType* newFlyer = (FlyerType*)malloc(sizeof(FlyerType));

    newFlyer->partInfo.avatar = avatar;
    newFlyer->partInfo.pos.row = row;
    newFlyer->partInfo.pos.col = col;
    newFlyer->strength = strength;

    addFlyer(&(escape->flyers), newFlyer);
}

void addFlyer(FlyerArrayType* flyerArray, FlyerType* flyer) {

    if (flyerArray->size < MAX_ARR) {
        flyerArray->elements[flyerArray->size++] = flyer;
    } else {
        printf("Flyer Array is full. Cannot add more flyers.\n");
    }

}

void moveFlyer(FlyerType* flyer, EscapeType* esc){
        if (flyer->partInfo.avatar == 'v'){
            flyer->partInfo.pos.row += 1;
            int num = randomInt(3);
            if (num == 0){
                flyer->partInfo.pos.col -= 1;
            } else if (num == 1){
                flyer->partInfo.pos.col += 1;
            }
            //printf("Bird\n");
            //printf("Col: %d, Row: %d\n", flyer->partInfo.pos.col, flyer->partInfo.pos.row);
        }

        else if (flyer->partInfo.avatar == '@'){
            //moving vertically
            int randomRow = randomIntRange(-3, 3);
            flyer->partInfo.pos.row += randomRow;
            //moving horizontally 
            int row = randomInt(3);
            int dir; 
            computeHeroDir(esc, flyer, &dir);
            if (dir == -1){
                flyer->partInfo.pos.col -= row;
            } else if (dir == 1){
                flyer->partInfo.pos.col += row; 
            }
            //printf("Monkey\n");
            //printf("Col: %d, Row: %d\n", flyer->partInfo.pos.col, flyer->partInfo.pos.row); 
        }
}

int flyerIsDone(FlyerType* flyer) {
        if (flyer->partInfo.pos.row >= MAX_ROW - 1){
            return C_TRUE;
        }
        return C_FALSE;
}



