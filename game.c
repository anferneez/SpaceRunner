#include "defaultlib.h"
#include "gamestatus.h"

#define DELAY 30000

int main()
{
	int ch, numAsteroids=50, maxy, maxx, gameover=0, score=0;
	asteroid Asteroids[numAsteroids];
	spaceship aSpaceship;

	gameinit();
	getmaxyx(stdscr, maxy, maxx);

	aSpaceship.starty=0.95*maxy;
	aSpaceship.startx=maxx/2;
	aSpaceship.height=2;

	makeAsteroid(Asteroids, numAsteroids, maxy, maxx);

	while (ch != KEY_F(1) && gameover==0)
	{
		clear();

		moveSpaceship(&aSpaceship, &ch, maxx);
		createSpaceship(&aSpaceship);
		moveAsteroid(Asteroids, maxy, maxx, numAsteroids);

		attron(COLOR_PAIR(4));
		mvprintw(3, maxx-10, "%d", score++);
		attroff(COLOR_PAIR(4));

		refresh();
		usleep(DELAY);
		
		gameover=checkGameover(Asteroids, aSpaceship, numAsteroids);
	}

	endwin();
}