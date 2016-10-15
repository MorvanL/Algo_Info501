CC=gcc
CFLAGS=-W -Wall -ansi -pedantic -O3
LDFLAGS= -lm
EXEC=progTri

all: $(EXEC)

$(EXEC): progTri.o tri.o tas.o util.o file.o
	$(CC) -o progTri progTri.o tri.o tas.o util.o file.o  

progTri.o: progTri.c tri.h tas.h util.h types.h file.h
	$(CC) -o progTri.o -c progTri.c 

tri.o: tri.c
	$(CC) -o tri.o -c tri.c 

tas.o: tas.c tas.h util.h types.h
	$(CC) -o tas.o -c tas.c 

util.o: util.c 
	$(CC) -o util.o -c util.c  

file.o: file.c file.h
	$(CC) -o file.o -c file.c 

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
