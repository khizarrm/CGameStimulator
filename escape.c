#include "defs.h"

/* SERVER FUNCTIONS */

//finish this 
void runEscape() {
    EscapeType* escape = malloc(sizeof(EscapeType));
    initEscape(escape);
    srand((unsigned int)time(NULL));

    while (escapeIsOver(escape) == C_FALSE){
        int number = randomInt(100);

        //80% probability of spawning a bird
        if (number < 80){
            int strength = randomIntRange(3, 5);
            int row = randomInt(5);
            int col = randomInt(MAX_COL-1) + 1;
            spawnFlyer(escape, 'v', strength, row, col);
        }

        //40% probability of spawning a monkey 
        /*if (number < 40){
            int row = randomIntRange(0, 14);
            int col = randomInt(MAX_COL-1) + 1;
            int strength = randomIntRange(8, 11);
            spawnFlyer(escape, '@', strength, row, col);
        }*/

        for (int i = 0; i < escape->heroes.size; i++){
            moveHero(escape->heroes.elements[i], escape);
        }

        for (int i = 0; i < escape->flyers.size; i++){
            moveFlyer(escape->flyers.elements[i], escape);
            HeroType *collision = checkForCollision(&escape->flyers.elements[i]->partInfo.pos, escape);
            if (collision != NULL){
                incurDamage(collision, escape->flyers.elements[i]);
            }
        }
    
        char hollow[MAX_ROW][MAX_COL];
        initHollow(escape, hollow);
        outputHollow(escape);
        sleep(1);
    }
}

int escapeIsOver(EscapeType* escape){
    for (int i = 0; i < 2; i++){
        if (heroIsSafe(escape->heroes.elements[i])){
            return escape->heroes.elements[i]->dead;
        }
    }
    return C_TRUE;
}

void initEscape(EscapeType* escape) {
    escape->flyers.size = 0;
    escape->heroes.size = 0;
    escape->heroes.elements = malloc(sizeof(HeroType*) * MAX_ARR);

    HeroType *timmy; 
    HeroType *harold; 

    srand((unsigned int)time(NULL));
    initHero(&timmy, 'T', randomInt(5) + 1, "Timmy");
    initHero(&harold, 'H', randomInt(5) + 1, "Harold");

    addHero(&(escape->heroes), timmy);
    addHero(&(escape->heroes), harold);
}

void handleEscapeResult(EscapeType* escape) {

}

void cleanupEscape(EscapeType* escape) {
    //cleaning up flyer array
    size_t fSize = escape->flyers.size;
    for (int i =0; i < fSize; i++){
        free(escape->flyers.elements[i]);
    }

    //cleaning up heroes array 
    size_t hSize = escape->heroes.size;
    for (int i = 0; i < hSize; i++){
        free(escape->heroes.elements[i]);
    }
    //sending quit message to client
}

/* CLIENT FUNCTION: */
/* top-level function for client process, given server IP address; */
/* sends connection request to server at given IP address, loops and
   waits for data that it prints out, until quit message is received */
void viewEscape(char*buffer);
