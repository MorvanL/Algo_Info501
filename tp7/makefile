CC=gcc
CFLAGS=-W -Wall -ansi -pedantic -O3
LDFLAGS= -lm
EXEC=Test

all: $(EXEC)

$(EXEC): Test.o graphe.o tableListesAdjacences.o listeAdjacences.o sommet.o outilsGraphe.o util.o file.o sommetPcc.o
	$(CC) -o Test Test.o  graphe.o  tableListesAdjacences.o listeAdjacences.o sommet.o outilsGraphe.o util.o file.o sommetPcc.o

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

outilsGraphe.o: outilsGraphe.c 
	$(CC) -o outilsGraphe.o -c outilsGraphe.c 
 
util.o: util.c 
	$(CC) -o util.o -c util.c  

file.o: file.c 
	$(CC) -o file.o -c file.c 

sommetPcc.o: sommetPcc.c 
	$(CC) -o sommetPcc.o -c sommetPcc.c 

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
