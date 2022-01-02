CC=gcc
FLAGS=-Wall -ggdb3 -g
OBJECTS_MAIN=main.o
LIB_OBJECTS=Graph.o
LIB_so=Graph.so


all: $(LIB_so) graph


#create main program
graph: $(OBJECTS_MAIN) $(LIB_so)
	$(CC) $(FLAGS) -o graph $(OBJECTS_MAIN) ./$(LIB_so) -lm



#clean
clean:
	rm *.o *.so graph

.PHONY: clean all


#compile dependencies
%.so: %.o
	$(CC) -shared -o $@ $<

%.a: %.o
	ar -rcs -o $@ $<

#compile objects
stringFunctions.o: Graph.h Graph.c
	$(CC) $(FLAGS) -c Graph.c


main.o: main.c Graph.h
	$(CC) $(FLAGS) -c main.c
