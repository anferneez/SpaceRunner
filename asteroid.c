#include "asteroid.h"
#include "defaultlib.h"

void moveAsteroid(asteroid* asteroids, int maxy, int maxx, int numAsteroids)
{
	for (int i=0; i<numAsteroids; i++)
	{
		asteroids[i].starty++;
		if (asteroids[i].starty>=maxy)
		{
			asteroids[i].starty=0;
			asteroids[i].startx= rand() % maxx;
		}
		attron(COLOR_PAIR(3));
		mvprintw(asteroids[i].starty, asteroids[i].startx, "    ");
		mvprintw(asteroids[i].starty+1, asteroids[i].startx, "    ");
		attroff(COLOR_PAIR(3));
	}
}

void makeAsteroid(asteroid* asteroids, int numAsteroids, int maxy, int maxx)
{
	for (int i=0; i<numAsteroids; i++)
	{
		asteroids[i].startx=rand() % maxx;
		asteroids[i].starty=-(rand() % maxy);
	}
}