#include "defaultlib.h"
#include "spaceship.h"
#include "asteroid.h"

int checkGameover(asteroid* Asteroids, spaceship aSpaceship, int numAsteroids);

void gameoverScreen(int score, int* key);

void gameinit();

void create_menu(WINDOW *menu_win, char** choices, int highlight, int n_choices);

void printMenu(WINDOW* menuWin, int maxy, int maxx, int* gameover, int* numAsteroids);
