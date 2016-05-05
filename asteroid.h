#include "defaultlib.h"

typedef struct
{
	int startx;
	int starty;
}asteroid;

void moveAsteroid(asteroid* asteroids, int maxy, int maxx, int numAsteroids);

void makeAsteroid(asteroid* asteroids, int numAsteroids, int maxy, int maxx);
