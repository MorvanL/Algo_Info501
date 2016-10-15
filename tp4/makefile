CC=gcc
CFLAGS=-W -Wall -ansi -pedantic -O3
LDFLAGS= -lm
EXEC=Test

all: $(EXEC)

$(EXEC): Test.o noeud.o Arbre.o outilsArbre.o pile.o
	$(CC) -o Test Test.o  noeud.o  Arbre.o outilsArbre.o pile.o

Test.o: Test.c 
	$(CC) -o Test.o -c Test.c 

Arbre.o: Arbre.c 
	$(CC) -o Arbre.o -c Arbre.c 

noeud.o: noeud.c 
	$(CC) -o noeud.o -c noeud.c 

outilsnoeud.o: outilsArbre.c 
	$(CC) -o outilsArbre.o -c outilsArbre.c 

pile.o: pile.c 
	$(CC) -o pile.o -c pile.c 

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
