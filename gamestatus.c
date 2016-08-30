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

void gameoverScreen(int score, int* key)
{
    init_pair(1, COLOR_WHITE, COLOR_WHITE);

    int x = 100;
    int y = 20;

    int m = x+8;
    int n = y+14;

    int scorex = m+20;
    int scorey = n+20;

    clear();
    while (*key!= KEY_F(1))
    {
        attron(COLOR_PAIR(1));

        mvprintw(y,x+4, "000000");
        mvprintw(y+1,x+3, "0");
        mvprintw(y+2,x+2, "0");
        mvprintw(y+3,x+1, "0");
        mvprintw(y+4,x, "0");
        mvprintw(y+5,x, "0");
        mvprintw(y+5,x+7, "000000");
        mvprintw(y+6,x, "0");
        mvprintw(y+6,x+12, "0");
        mvprintw(y+7,x+1, "0");
        mvprintw(y+7,x+12, "0");
        mvprintw(y+8,x+2, "0");
        mvprintw(y+8,x+12,"0");
        mvprintw(y+9,x+3, "0");
        mvprintw(y+9,x+11, "0");
        mvprintw(y+10,x+4, "0000000");

        mvprintw(y,x+24, "0");
        mvprintw(y+1,x+23, "0");
        mvprintw(y+1,x+25, "0");
        mvprintw(y+2,x+22, "0");
        mvprintw(y+2,x+26, "0");
        mvprintw(y+3,x+21, "0");
        mvprintw(y+3,x+27, "0");
        mvprintw(y+4,x+20, "0");
        mvprintw(y+4,x+28, "0");
        mvprintw(y+5,x+19, "00000000000");
        mvprintw(y+6,x+18, "0");
        mvprintw(y+6,x+30, "0");
        mvprintw(y+7,x+17, "0");
        mvprintw(y+7,x+31, "0");
        mvprintw(y+8,x+16, "0");
        mvprintw(y+8,x+32, "0");
        mvprintw(y+9,x+15, "0");
        mvprintw(y+9,x+33, "0");
        mvprintw(y+10,x+14, "0");
        mvprintw(y+10,x+34, "0");

        mvprintw(y,x+40, "0");
        mvprintw(y+1,x+40, "00");
        mvprintw(y+2,x+40, "0");
        mvprintw(y+3,x+40, "0");
        mvprintw(y+4,x+40, "0");
        mvprintw(y+5,x+40, "0");
        mvprintw(y+6,x+40, "0");
        mvprintw(y+7,x+40, "0");
        mvprintw(y+8,x+40, "0");
        mvprintw(y+9,x+40, "0");
        mvprintw(y+10,x+40, "0");
        mvprintw(y+2,x+42, "0");
        mvprintw(y+3,x+42, "0");
        mvprintw(y+4,x+43, "0");
        mvprintw(y+5,x+44, "0");
        mvprintw(y+6,x+44, "0");
        mvprintw(y+7,x+45, "0");
        mvprintw(y+8,x+46, "0");
        mvprintw(y+9,x+47, "0");
        mvprintw(y+10,x+48, "0");
        mvprintw(y+9,x+49, "0");
        mvprintw(y+8,x+50, "0");
        mvprintw(y+7,x+51, "0");
        mvprintw(y+6,x+52, "0");
        mvprintw(y+5,x+53, "0");
        mvprintw(y+4,x+54, "0");
        mvprintw(y+3,x+55, "0");
        mvprintw(y+2,x+56, "0");
        mvprintw(y+1,x+57, "00");
        mvprintw(y,x+58, "0");
        mvprintw(y+2,x+58, "0");
        mvprintw(y+3,x+58, "0");
        mvprintw(y+4,x+58, "0");
        mvprintw(y+5,x+58, "0");
        mvprintw(y+6,x+58, "0");
        mvprintw(y+7,x+58, "0");
        mvprintw(y+8,x+58, "0");
        mvprintw(y+9,x+58, "0");
        mvprintw(y+10,x+58, "0");

        mvprintw(y,x+62, "00000000000");
        mvprintw(y+1,x+62, "0");
        mvprintw(y+2,x+62, "0");
        mvprintw(y+3,x+62, "0");
        mvprintw(y+4,x+62, "0");
        mvprintw(y+5,x+62, "0000000");
        mvprintw(y+6,x+62, "0");
        mvprintw(y+7,x+62, "0");
        mvprintw(y+8,x+62, "0");
        mvprintw(y+9,x+62, "0");
        mvprintw(y+10,x+62, "00000000000");


        mvprintw(n, m+4, "0000");
        mvprintw(n+1,m+3, "0");
        mvprintw(n+2,m+2, "0");
        mvprintw(n+3,m+1, "0");
        mvprintw(n+4,m, "0");
        mvprintw(n+5,m, "0");
        mvprintw(n+6,m, "0");
        mvprintw(n+7,m+1, "0");
        mvprintw(n+8,m+2, "0");
        mvprintw(n+9,m+3, "0");
        mvprintw(n+10,m+4, "0000");
        mvprintw(n+1,m+8, "0");
        mvprintw(n+2,m+9, "0");
        mvprintw(n+3,m+10, "0");
        mvprintw(n+4,m+11, "0");
        mvprintw(n+5,m+11, "0");
        mvprintw(n+6,m+11, "0");
        mvprintw(n+7,m+10, "0");
        mvprintw(n+8,m+9, "0");
        mvprintw(n+9,m+8, "0");

        mvprintw(n,m+13, "0");
        mvprintw(n+1,m+14, "0");
        mvprintw(n+2,m+15, "0");
        mvprintw(n+3,m+16, "0");
        mvprintw(n+4,m+17, "0");
        mvprintw(n+5,m+18, "0");
        mvprintw(n+6,m+19, "0");
        mvprintw(n+7,m+20, "0");
        mvprintw(n+8,m+21, "0");
        mvprintw(n+9,m+22, "0");
        mvprintw(n+10,m+23, "0");
        mvprintw(n,m+33, "0");
        mvprintw(n+1,m+32, "0");
        mvprintw(n+2,m+31, "0");
        mvprintw(n+3,m+30, "0");
        mvprintw(n+4,m+29, "0");
        mvprintw(n+5,m+28, "0");
        mvprintw(n+6,m+27, "0");
        mvprintw(n+7,m+26, "0");
        mvprintw(n+8,m+25, "0");
        mvprintw(n+9,m+24, "0");

        mvprintw(n,m+35, "00000000000");
        mvprintw(n+1,m+35, "0");
        mvprintw(n+2,m+35, "0");
        mvprintw(n+3,m+35, "0");
        mvprintw(n+4,m+35, "0");
        mvprintw(n+5,m+35, "0000000");
        mvprintw(n+6,m+35, "0");
        mvprintw(n+7,m+35, "0");
        mvprintw(n+8,m+35, "0");
        mvprintw(n+9,m+35, "0");
        mvprintw(n+10,m+35, "00000000000");

        mvprintw(n,m+48, "00000000");
        mvprintw(n+1,m+48, "0");
        mvprintw(n+2,m+48, "0");
        mvprintw(n+3,m+48, "0");
        mvprintw(n+4,m+48, "0");
        mvprintw(n+5,m+48, "00000000");
        mvprintw(n+6,m+48, "0");
        mvprintw(n+7,m+48, "0");
        mvprintw(n+8,m+48, "0");
        mvprintw(n+9,m+48, "0");
        mvprintw(n+10,m+48, "0");
        mvprintw(n+1,m+56, "0");
        mvprintw(n+2,m+57, "0");
        mvprintw(n+3,m+57, "0");
        mvprintw(n+4,m+56, "0");
        mvprintw(n+6,m+56, "0");
        mvprintw(n+7,m+57, "0");
        mvprintw(n+8,m+58, "0");
        mvprintw(n+9,m+58, "0");
        mvprintw(n+10,m+58, "0");

        attroff(COLOR_PAIR(1));

        mvprintw(scorey, scorex, "Your score is %d", score);

        *key = getch();
        refresh();
    }
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