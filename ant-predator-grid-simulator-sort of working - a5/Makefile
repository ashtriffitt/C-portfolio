IDIR =../include
CC=g++
CFLAGS= -I$(IDIR) -g -std=c++11 -O0

ODIR=.

LIBS=-lncurses

_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

OBJECTS = main.o Ant.o FemaleDoodlebug.o Grid.o MaleDoodlebug.o Organism.o

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
	
main: $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

$(OBJECTS): Ant.h FemaleDoodlebug.h Grid.h MaleDoodlebug.h Organism.h

.PHONY: clean

clean:
	rm -f *~ core $(INCDIR)/*~ 
	rm -f main
	rm -f *.o

etags: 
	find . -type f -iname "*.[ch]" | xargs etags --append 