CC=gcc
CFLAGS=-W -Wall -ansi -pedantic -O3
LDFLAGS= -lm
EXEC=Test

all: $(EXEC)

$(EXEC): Test.o pile.o outilsPile.o hanoi.o
	$(CC) -o Test Test.o  pile.o  outilsPile.o hanoi.o

Test.o: Test.c pile.h hanoi.h
	$(CC) -o Test.o -c Test.c 

pile.o: pile.c pile.h
	$(CC) -o pile.o -c pile.c 

outilsPile.o: outilsPile.c outilsPile.h
	$(CC) -o outilsPile.o -c outilsPile.c 

hanoi.o: hanoi.c  hanoi.h
	$(CC) -o hanoi.o -c hanoi.c 

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
