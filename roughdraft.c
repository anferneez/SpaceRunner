
#include <ncurses.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DELAY 30000

typedef struct asteroid
{
	int positiony;
	int positionx;
}asteroid;

typedef struct spaceship
{
	int starty;
	int startx;
	int height;
}spaceship;

void createSpaceship(spaceship* aSpaceship);
int kbhit(void);
void moveAsteroid(asteroid* asteroids, int maxy, int maxx, int numAsteroids);
void makeAsteroid(asteroid* asteroids, int numAsteroids, int maxy, int maxx);
void printGameOver();
void print_menu(WINDOW *menu_win, int highlight, int n_choices);

#define WIDTH 30
#define HEIGHT 10 

int startx = 0;
int starty = 0;

char *choices[] = { 
			"Easy",
			"Normal",
			"Hard",
			"Impossible",
			"Exit",
		  };


int main()
{
	int startx = 0;
	int starty = 0;

	char *choices[] = { 
			"Easy",
			"Normal",
			"Hard",
			"Impossible",
			"Exit",
		  };

	int n_choices = sizeof(choices) / sizeof(char *);
	WINDOW *menu_win;
	int highlight = 1;
	int choice = 0;
	int c;

	initscr();
	clear();
	noecho();
	cbreak();	/* Line buffering disabled. pass on everything */
	

	start_color();
	keypad(stdscr, TRUE);
	curs_set(0);

	int max_y, max_x = 0;
	getmaxyx(stdscr, max_y, max_x);

	startx = (max_x / 2) - WIDTH;
	starty = (max_y / 2) - HEIGHT;

	int ch;
		
	menu_win = newwin(HEIGHT, WIDTH, starty, startx);
	keypad(menu_win, TRUE);
	mvprintw(0, 0, "Use arrow keys to go up and down, Press enter to select a choice");
	refresh();
	print_menu(menu_win, highlight, n_choices);
	while(1)
	{	c = wgetch(menu_win);
		switch(c)
		{	case KEY_UP:
				if(highlight == 1)
					highlight = n_choices;
				else
					--highlight;
				break;
			case KEY_DOWN:
				if(highlight == n_choices)
					highlight = 1;
				else 
					++highlight;
				break;
			case 10:
				choice = highlight;
				break;
		}
		print_menu(menu_win, highlight, n_choices);
		if(choice != 0)	/* User did a choice come out of the infinite loop */
			break;
	}


	init_pair(1, COLOR_WHITE, COLOR_WHITE);
	init_pair(2, COLOR_RED, COLOR_RED);
	init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
	init_pair(4, COLOR_RED, COLOR_BLACK);

	int numasteroid;
	int gameover = 0;

	if(choice == 1)
		numasteroid = 50;
	else if (choice == 2)
		numasteroid = 100;
	else if (choice == 3)
		numasteroid = 200;
	else if (choice == 4)
		numasteroid = 1000;
	else if (choice == 5)
	{
		numasteroid = 0;
		gameover = 1;
	}

	asteroid dumb[numasteroid];
	spaceship idiot;
	idiot.startx = max_x/2;
	idiot.starty = 0.95*max_y;
	idiot.height = 2;

	int score = 0;

	makeAsteroid(dumb, numasteroid, max_y, max_x);
	createSpaceship(&idiot);

	while(gameover != 1)
	{	
		clear();
		createSpaceship(&idiot);

		if (kbhit())
		{
			ch = getch();

			if (ch == KEY_LEFT && idiot.startx != 3)
				idiot.startx = idiot.startx - 3;
			else if (ch == KEY_RIGHT && idiot.startx != (max_x-4))
				idiot.startx = idiot.startx + 3;
		}
		

		attron(COLOR_PAIR(3));
		moveAsteroid(dumb, max_y, max_x, numasteroid);

		attron(COLOR_PAIR(4));
		mvprintw(3,max_x-10, "%d", score);
		attroff(COLOR_PAIR(4));

		refresh();

		for (int a = 0; a < numasteroid; a++)
		{
			for (int b = 0; b < 4; b++)
			{
				if (dumb[a].positiony + 1 == idiot.starty)
				{
					if (dumb[a].positionx >= idiot.startx - 3 && dumb[a].positionx <= idiot.startx + 3)
						gameover = 1;
				}
			}
		}

		score++;
		usleep(DELAY);
		attroff(COLOR_PAIR(3));
	}

	while (ch != KEY_F(1))
	{
		clear();
		printGameOver(ch);
		refresh();
	}
	endwin();
	return 0;
}


void print_menu(WINDOW *menu_win, int highlight, int n_choices)
{
	int x, y, i;	

	x = 2;
	y = 2;
	box(menu_win, 0, 0);
	for(i = 0; i < n_choices; ++i)
	{	if(highlight == i + 1) /* High light the present choice */
		{	wattron(menu_win, A_REVERSE); 
			mvwprintw(menu_win, y, x, "%s", choices[i]);
			wattroff(menu_win, A_REVERSE);
		}
		else
			mvwprintw(menu_win, y, x, "%s", choices[i]);
		++y;
	}
	wrefresh(menu_win);
}

int kbhit(void)
{
    int ch, r;

    nodelay(stdscr, TRUE);
    noecho();

    ch = getch();
    if( ch == ERR)
            r = FALSE;
    else
    {
            r = TRUE;
            ungetch(ch);
    }

    echo();
    nodelay(stdscr, FALSE);
    return(r);
}

void moveAsteroid(asteroid* asteroids, int maxy, int maxx, int numAsteroids)
{
	for (int i=0; i<numAsteroids; i++)
	{
		asteroids[i].positiony++;
		if (asteroids[i].positiony>=maxy)
		{
			asteroids[i].positiony=0;
			asteroids[i].positionx= rand() % maxx;
		}
		mvprintw(asteroids[i].positiony, asteroids[i].positionx, "    ");
		mvprintw(asteroids[i].positiony+1, asteroids[i].positionx, "    ");
	}
}

void makeAsteroid(asteroid* asteroids, int numAsteroids, int maxy, int maxx)
{
	for (int i=0; i<numAsteroids; i++)
	{
		asteroids[i].positionx=rand() % maxx;
		asteroids[i].positiony=-(rand() % maxy);
	}
}

void createSpaceship(spaceship* aSpaceship)
{
	 int x=aSpaceship->startx;
	 attron(COLOR_PAIR(1));
	 int y=aSpaceship->startx;

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
    mvprintw(aSpaceship->starty + 3, y + 6, "*");
    mvprintw(aSpaceship->starty + 3, y, "*");
    attroff(COLOR_PAIR(2));
}

void printGameOver(int ch)
{
	int x = 20;
	int y = 20;

	init_pair(1, COLOR_WHITE, COLOR_WHITE);

	clear();
	while (ch!= KEY_F(1))
	{
		attron(COLOR_PAIR(1));
		ch = getch();
		mvprintw(y,x+2,"000");
		mvprintw(y,x+14,"0");
		mvprintw(y,x+23,"0");
		mvprintw(y,x+35,"0");
		mvprintw(y,x+38,"00000000");
	
		mvprintw(y+1,x+1,"0");
		mvprintw(y+1,x+13,"0");
		mvprintw(y+1,x+15,"0");
		mvprintw(y+1,x+23,"00");
		mvprintw(y+1,x+34,"00");
		mvprintw(y+1,x+38,"0");

		mvprintw(y+2,x,"0");
		mvprintw(y+2,x+12,"0");
		mvprintw(y+2,x+16,"0");
		mvprintw(y+2,x+23,"0");
		mvprintw(y+2,x+25,"0");
		mvprintw(y+2,x+33,"0");
		mvprintw(y+2,x+35,"0");
		mvprintw(y+2,x+38,"0");

		mvprintw(y+3,x,"0");
		mvprintw(y+3,x+11,"0");
		mvprintw(y+3,x+17,"0");
		mvprintw(y+3,x+23,"0");
		mvprintw(y+3,x+26,"0");
		mvprintw(y+3,x+32,"0");
		mvprintw(y+3,x+35,"0");
		mvprintw(y+3,x+38,"00000");	

		mvprintw(y+4,x,"0");
		mvprintw(y+4,x+3,"0000");
		mvprintw(y+4,x+10,"000000000");
		mvprintw(y+4,x+23,"0");
		mvprintw(y+4,x+27,"0");
		mvprintw(y+4,x+31,"0");
		mvprintw(y+4,x+35,"0");
		mvprintw(y+4,x+38,"0");

		mvprintw(y+5,x+1,"0");
		mvprintw(y+5,x+5,"0");
		mvprintw(y+5,x+9,"0");
		mvprintw(y+5,x+19,"0");
		mvprintw(y+5,x+23,"0");
		mvprintw(y+5,x+28,"0");
		mvprintw(y+5,x+30,"0");
		mvprintw(y+5,x+35,"0");
		mvprintw(y+5,x+38,"0");

		mvprintw(y+6,x+2,"000");
		mvprintw(y+6,x+8,"0");
		mvprintw(y+6,x+20,"0");
		mvprintw(y+6,x+23,"0");
		mvprintw(y+6,x+29,"0");
		mvprintw(y+6,x+35,"0");
		mvprintw(y+6,x+38,"00000000");

		attroff(COLOR_PAIR(1));

	}






}
