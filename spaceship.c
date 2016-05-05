#include "defaultlib.h"
#include "spaceship.h"

void createSpaceship(spaceship* aSpaceship)
{
	int x=aSpaceship->startx;
	int y=aSpaceship->startx;
	attron(COLOR_PAIR(1));

	for(int r=aSpaceship->starty; r<=(aSpaceship->starty + aSpaceship->height); r++)
	{
		for(int c=y; c<=x; c++)
		{
			move(r,c);
			printw("*");
		}
		x++;
		y--;
	}

	attroff(COLOR_PAIR(1));
	mvprintw(aSpaceship->starty + 1, y + 6, "*");
	mvprintw(aSpaceship->starty + 1, y, "*");

	attron(COLOR_PAIR(2));
    mvprintw(aSpaceship->starty + 3, y, "*");
    mvprintw(aSpaceship->starty + 3, y + 6, "*");
    attroff(COLOR_PAIR(2));
}

int kbhit(void)    /* comment */
{
    int ch, r;

    // turn off getch() blocking and echo
    nodelay(stdscr, TRUE);
    noecho();

    // check for input
    ch = getch();
    if( ch == ERR)      // no input
        r = FALSE;
    else                // input
    {
        r = TRUE;
    	ungetch(ch);
    }

    // restore block and echo
    echo();
    nodelay(stdscr, FALSE);
    return(r);
}

void moveSpaceship(spaceship* aSpaceship, int* key, int maxx)
{
	if (kbhit())
	{
		*key=getch();
		if (*key == KEY_LEFT && aSpaceship->startx != 3)
			aSpaceship->startx-=3;
		else if (*key == KEY_RIGHT && aSpaceship->startx != (maxx-4))
			aSpaceship->startx+=3;
	}
}