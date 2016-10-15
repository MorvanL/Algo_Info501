CC=gcc
CFLAGS=-W -Wall -ansi -pedantic -O3
LDFLAGS= -lm
EXEC=Test

all: $(EXEC)

$(EXEC): Test.o graphe.o tableListesAdjacences.o listeAdjacences.o sommet.o composante.o ensemble.o arete.o outilsGraphe.o tas.o util.o file.o sommetPrim.o
	$(CC) -o Test Test.o  graphe.o  tableListesAdjacences.o listeAdjacences.o sommet.o  composante.o ensemble.o arete.o outilsGraphe.o tas.o util.o file.o sommetPrim.o

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

composante.o: composante.c
	$(CC) -o composante.o -c composante.c 

ensemble.o: ensemble.c
	$(CC) -o ensemble.o -c ensemble.c 

arete.o: arete.c 
	$(CC) -o arete.o -c arete.c 

outilsGraphe.o: outilsGraphe.c 
	$(CC) -o outilsGraphe.o -c outilsGraphe.c 
 
tas.o: tas.c 
	$(CC) -o tas.o -c tas.c 

util.o: util.c 
	$(CC) -o util.o -c util.c  

file.o: file.c 
	$(CC) -o file.o -c file.c 

sommetPrim.o: sommetPrim.c 
	$(CC) -o sommetPrim.o -c sommetPrim.c 


clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
