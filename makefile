game:main.o
	gcc main.o -o game -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf  -g 
	
clean:
	rm -f *.o core	
mrproper: clean
	rm -f ./game
