#include "defs.h"

void initHero(HeroType** hero, char avatar, int col, char* name) {
    *hero = (HeroType*)malloc(sizeof(HeroType));
    (*hero)->partInfo.avatar = avatar;
    (*hero)->health = MAX_HEALTH;
    (*hero)->partInfo.pos.col = col;
    (*hero)->partInfo.pos.row = MAX_ROW - 1;
    (*hero)->dead = C_FALSE;
    strcpy((*hero)->name, name);
}

/* adds hero to escape's hero collection */
void addHero(HeroArrayType* heroarr, HeroType* hero) {
    if (heroarr->size < MAX_ARR) {
        heroarr->elements[heroarr->size++] = hero;
    } else {
        printf("Hero Array is full. Cannot add more heroes.\n");
    }
}

void moveHero(HeroType* hero, EscapeType* escape) {
    //randomizing the seed
    srand(time(NULL)); 
    int num = randomInt(100);

    //do this if the hero isnt dead
    if (hero->dead != C_TRUE){
        //if hero is timmy 
        if (hero->partInfo.avatar == 'T'){
            if (num < 50){
                hero->partInfo.pos.col += 2;
            } else if (num < 80){
                hero->partInfo.pos.col -= 1;
            } else if (num < 100){
                hero->partInfo.pos.col += 1;
            }
        }

        //if hero is harold
        if (hero->partInfo.avatar == 'H'){
            if (num < 30){
                hero->partInfo.pos.col += 5;
            } else if (num < 40){
                hero->partInfo.pos.col -= 4;
            } else if (num < 80){
                hero->partInfo.pos.col += 3;
            } else if (num < 100){
                hero->partInfo.pos.col -= 2;
            }
        }

        //condition to make sure hero is in bounds
        if (hero->partInfo.pos.col < 0){
            hero->partInfo.pos.col = 0;
        }
        }

}

int heroIsSafe(HeroType* hero) {
    if (hero->partInfo.pos.col > MAX_COL){
        return C_FALSE;
    }
    return C_TRUE;
}

void incurDamage(HeroType* hero, FlyerType* flyer) {
    hero->health -= flyer->strength;
    if (hero->health <= 0) {
        hero->dead = C_TRUE;
        hero->partInfo.avatar = '+';
        hero->health = 0; 
    }
}

