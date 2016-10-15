CC=gcc
CFLAGS=-W -Wall -ansi -pedantic -O3
LDFLAGS= -lm
EXEC=Test

all: $(EXEC)

$(EXEC): Test.o liste.o cellule.o outilsListe.o tableHachage.o outilsTableHachage.o
	$(CC) -o Test Test.o liste.o  cellule.o outilsListe.o tableHachage.o outilsTableHachage.o $(LDFLAGS)

Test.o: Test.c outilsTableHachage.h
	$(CC) -o Test.o -c Test.c 

outilsTableHachage.o: outilsTableHachage.c outilsTableHachage.h
	$(CC) -o outilsTableHachage.o -c outilsTableHachage.c

tableHachage.o: tableHachage.c tableHachage.h
	$(CC) -o tableHachage.o -c tableHachage.c 

outilsListe.o: outilsListe.c outilsListe.h
	$(CC) -o outilsListe.o -c outilsListe.c 

liste.o: liste.c liste.h
	$(CC) -o liste.o -c liste.c 

cellule.o: cellule.c cellule.h
	$(CC) -o cellule.o -c cellule.c 

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
