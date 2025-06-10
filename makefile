CC = gcc
CFLAGS = -Wall -Wextra

all: main_program

main_program: main.o binary-tree.o
	$(CC) $(CFLAGS) -o main_program main.o binary-tree.o

main.o: main.c binary-tree.h
	$(CC) $(CFLAGS) -c -o main.o main.c

binary-tree.o: binary-tree.c binary-tree.h
	$(CC) $(CFLAGS) -c -o binary-tree.o binary-tree.c

clear:
	del /Q main_program.exe *.o
