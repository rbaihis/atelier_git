test:main.o background.o
	gcc main.o background.o -o test -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf  -g
main.o:main.c
	gcc -c main.c   -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf  -g
background.o:background.c
	gcc -c background.c   -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf  -g
