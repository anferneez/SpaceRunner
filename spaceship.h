#include "defaultlib.h"

typedef struct
{
	int starty;
	int startx;
	int height;
}spaceship;

void createSpaceship(spaceship* aSpaceship);

int kbhit(void);

void moveSpaceship(spaceship* aSpaceship, int* key, int maxx);