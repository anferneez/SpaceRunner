asteroid.o: asteroid.c asteroid.h defaultlib.h
	gcc -c asteroid.c

spaceship.o: spaceship.c spaceship.h defaultlib.h
	gcc -c spaceship.c

gamestatus.o: gamestatus.c spaceship.h asteroid.h gamestatus.h defaultlib.h
	gcc -c gamestatus.c

game.o: game.c defaultlib.h spaceship.h asteroid.h gamestatus.h
	gcc -c game.c

project: asteroid.o spaceship.o gamestatus.o game.o
	gcc asteroid.o spaceship.o gamestatus.o game.o -lncurses