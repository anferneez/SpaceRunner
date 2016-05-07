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
    noecho();
    cbreak();
    clear();
	init_pair(1, COLOR_WHITE, COLOR_WHITE);
	init_pair(2, COLOR_RED, COLOR_RED);
	init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(4, COLOR_BLACK, COLOR_WHITE);
}

void create_menu(WINDOW *menu_win, char** choices, int highlight, int n_choices)
{
    int x, y;    

    x = 2;
    y = 2;
    box(menu_win, 0, 0);
    for(int i = 0; i < n_choices; ++i)
    {   
        if(highlight == i + 1) /* High light the present choice */
        {   wattron(menu_win, A_REVERSE); 
            mvwprintw(menu_win, y, x, "%s", choices[i]);
            wattroff(menu_win, A_REVERSE);
        }
        else
            mvwprintw(menu_win, y, x, "%s", choices[i]);
        ++y;
    }
    wrefresh(menu_win);
}

void printMenu(WINDOW* menuWin, int maxy, int maxx, int* gameover, int* numAsteroids)
{
    int menustarty, menustartx, nchoices, choice=0, highlight=1, c;
    char* choices[] = { 
        "Easy",
        "Normal",
        "Hard",
        "Impossible",
        "Exit",
    };
    
    nchoices=sizeof(choices)/sizeof(char*);
    menustarty=maxy/2-10;
    menustartx=maxx/2-30;
    menuWin= newwin(10, 30, menustarty, menustartx);
    keypad(menuWin, TRUE);
    mvprintw(0, 0, "Use arrow keys to go up and down, Press enter to select a choice");
    refresh();

    create_menu(menuWin, choices, highlight, nchoices);
    while(1)
    {   
        c = wgetch(menuWin);
        switch(c)
        {   case KEY_UP:
                if(highlight == 1)
                    highlight = nchoices;
                else
                    --highlight;
                break;
            case KEY_DOWN:
                if(highlight == nchoices)
                    highlight = 1;
                else 
                    ++highlight;
                break;
            case 10:
                choice = highlight;
                break;
        }
        create_menu(menuWin, choices, highlight, nchoices);
        if(choice != 0) /* User did a choice come out of the infinite loop */
            break;
    }

    if(choice == 1)
        *numAsteroids = 50;
    else if (choice == 2)
        *numAsteroids = 100;
    else if (choice == 3)
        *numAsteroids = 200;
    else if (choice == 4)
        *numAsteroids = 1000;
    else if (choice == 5)
    {
        *numAsteroids = 0;
        *gameover = 1;
    }
}