#include "asteroid.h"
#include "spaceship.h"
#include "defaultlib.h"

int checkGameover(asteroid* Asteroids, spaceship aSpaceship, int numAsteroids)
{
    int endGame=0;
    int lowerEndShip=aSpaceship.startx-3;
    int higherEndShip=aSpaceship.startx+3;
    int lowerEndAst, higherEndAst;

    for (int i=0; i<numAsteroids; i++)
    {
        lowerEndAst=Asteroids[i].startx;
        higherEndAst=Asteroids[i].startx+3;

        if (Asteroids[i].starty==aSpaceship.starty)
        {
            if (((lowerEndShip<=higherEndAst) && (higherEndAst<=higherEndShip)) || ((lowerEndAst<=higherEndShip) && (higherEndShip<=higherEndAst)))
                endGame=1;
            else
                endGame=0;
        }
    }
    return (endGame);
}

void gameinit()
{
	initscr();
	start_color();
	keypad(stdscr, TRUE);
	curs_set(0);
	init_pair(1, COLOR_WHITE, COLOR_WHITE);
	init_pair(2, COLOR_RED, COLOR_RED);
	init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(4, COLOR_BLACK, COLOR_WHITE);
}