CC=gcc
CFLAGS=-W -Wall -ansi -pedantic -O3
LDFLAGS= -lm
EXEC=Test

all: $(EXEC)

$(EXEC): Test.o graphe.o tableListesAdjacences.o listeAdjacences.o sommet.o sommetParcours.o file.o outilsGraphe.o
	$(CC) -o Test Test.o  graphe.o  tableListesAdjacences.o listeAdjacences.o sommet.o sommetParcours.o file.o outilsGraphe.o

Test.o: Test.c 
	$(CC) -o Test.o -c Test.c 

graphe.o: graphe.c 
	$(CC) -o graphe.o -c graphe.c 

tableListesAdjacences.o: tableListesAdjacences.c 
	$(CC) -o tableListesAdjacences.o -c tableListesAdjacences.c 

listeAdjacences.o: listeAdjacences.c 
	$(CC) -o listeAdjacences.o -c listeAdjacences.c 

sommet.o: sommet.c 
	$(CC) -o sommet.o -c sommet.c 

sommetParcours.o: sommetParcours.c 
	$(CC) -o sommetParcours.o -c sommetParcours.c 

file.o: file.c 
	$(CC) -o file.o -c file.c 

outilsGraphe.o: outilsGraphe.c
	$(CC) -o outilsGraphe.o -c outilsGraphe.c 

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
