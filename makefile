prog:main.o
	gcc main.o -o prog -g
main.o:main.c
	gcc -c main.c -g
