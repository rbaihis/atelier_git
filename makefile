test:main.o background.o ennemi.o perso.o
	gcc main.o background.o ennemi.o perso.o -o test -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf  -g
main.o:main.c
	gcc -c main.c  -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf  -g
background.o:background.c
	gcc -c background.c   -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf  -g
ennemi.o:ennemi.c
	gcc -c ennemi.c   -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf  -g
perso.o:perso.c
	gcc -c perso.c   -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf  -g

clean:
	rm -fr test main.o background.o ennemi.o perso.o
execute:
	./test
