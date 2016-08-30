#include "defaultlib.h"
#include "gamestatus.h"

#define DELAY 35000

int main()
{
	WINDOW* menuWin;
	int ch, numAsteroids, maxy, maxx, gameover=0, score=0;
	spaceship aSpaceship;

	gameinit();

	getmaxyx(stdscr, maxy, maxx);

	aSpaceship.starty=0.95*maxy;
	aSpaceship.startx=maxx/2;
	aSpaceship.height=2;

	printMenu(menuWin, maxy, maxx, &gameover, &numAsteroids);

	asteroid Asteroids[numAsteroids];
	makeAsteroid(Asteroids, numAsteroids, maxy, maxx);

	while (ch != KEY_F(1) && gameover==0)
	{
		clear();

		moveSpaceship(&aSpaceship, &ch, maxx);
		createSpaceship(&aSpaceship);
		moveAsteroid(Asteroids, maxy, maxx, numAsteroids);

		attron(COLOR_PAIR(4));
		mvprintw(2, maxx-10, "%s", "SCORE:");
		mvprintw(3, maxx-10, "%d", score++);
		attroff(COLOR_PAIR(4));

		wrefresh(stdscr);
		usleep(DELAY);
		
		gameover=checkGameover(Asteroids, aSpaceship, numAsteroids);
	}

	while (ch != KEY_F(1))
	{
		gameoverScreen(score, &ch);
	}

	endwin();
}