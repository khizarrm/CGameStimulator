#include "defs.h"

void outputHollow(EscapeType* escape) {
    char s[MAX_BUFF];
    serializeHollow(escape, s);
    printf("%s", s);
    for (int i = 0; i < escape->heroes.size; i++){
        printf("%s: %d \n", escape->heroes.elements[i]->name, escape->heroes.elements[i]->health);
    }
}

void initHollow(EscapeType* escape, char hollowArray[][MAX_COL]) {
    for (int i = 0; i < MAX_ROW; i++){
        for (int j = 0; j < MAX_COL; j++){
            hollowArray[i][j] = ' ';
        }
    }

    HeroArrayType heroes = escape->heroes;
    for (int i = 0; i < escape->heroes.size; i++){
        hollowArray[MAX_ROW-1][(heroes.elements[i]->partInfo.pos.col)] = heroes.elements[i]->partInfo.avatar;
    }

    //add the flyers
    FlyerArrayType flyers = escape->flyers;
    for (int i = 0; i < escape->flyers.size; i++){
        hollowArray[flyers.elements[i]->partInfo.pos.row][flyers.elements[i]->partInfo.pos.col] = flyers.elements[i]->partInfo.avatar;
    }

}


void serializeHollow(EscapeType* escape, char* serializedArray) {
    int index = 0;
    char hollow[MAX_ROW][MAX_COL];
    initHollow(escape, hollow);

    // Add top boundary
    for (int i = 0; i < MAX_COL + 2; i++) {
        serializedArray[index++] = '-';
    }
    serializedArray[index++] = '\n';

    // Iterate over the 2D array and copy each character to the serialized string
    for (int i = 0; i < MAX_ROW; i++) {
        if (i == MAX_ROW - 1){
            serializedArray[index++] = '=';
        } else {
            serializedArray[index++] = '|';
        }

        for (int j = 0; j < MAX_COL; j++) {
            serializedArray[index++] = hollow[i][j];

            // Add a newline after each row
            if (j == MAX_COL - 1) {
                if (i == MAX_ROW - 1) {
                    serializedArray[index++] = '=';
                } else {
                    serializedArray[index++] = '|';
                }
                serializedArray[index++] = '\n';
            }
        }
    }

    // Add bottom boundary
    for (int i = 0; i < MAX_COL + 2; i++) {
        serializedArray[index++] = '-';
    }
    serializedArray[index++] = '\n';
}

