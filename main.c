#include "defs.h"

int main(int argc, char *argv[])
{
  runEscape();
  /*EscapeType *game = malloc(sizeof(EscapeType));
  initEscape(game);
  srand((unsigned int)time(NULL));
  char *x = malloc(sizeof(char)*MAX_BUFF);
  serializeHollow(game, x);
  printf("%s", x);
  return(0);*/
}

int randomInt(int max)
{
  return(rand() % max);
}

