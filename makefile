CC=gcc
FLAGS=-Wall -fPIC -ggdb3 -g
OBJECTS_MAIN=main.o



all: lib.so graph

#create main program
graph: lib.so $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o graph $(OBJECTS_MAIN) ./lib.so -lm
#


#clean
clean:
	rm *.o *.so graph

.PHONY: clean all



#compile objects
List.o: List.h List.c
	$(CC) $(FLAGS) -c List.c

Node.o: List.h Node.c
	$(CC) $(FLAGS) -c Node.c List.c

Graph.o: List.h Graph.h Graph.c
	$(CC) $(FLAGS) -c Graph.c List.c

lib.so: Graph.o List.o
	$(CC) -shared Graph.o List.o -o $@

main.o: main.c Graph.h
	$(CC) $(FLAGS) -c main.c
