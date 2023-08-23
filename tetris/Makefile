IDIR =../include
CC=g++
CFLAGS= -I$(IDIR) -g -std=c++11 -O0

ODIR=.

LIBS=-lncurses

_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

OBJECTS = main.o game.o key.o tetromino.o well.o

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
	
main: $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

$(OBJECTS): game.hpp key.hpp tetromino.hpp well.hpp tetris.hpp

.PHONY: clean

clean:
	rm -f *~ core $(INCDIR)/*~ 
	rm -f main
	rm -f *.o

etags: 
	find . -type f -iname "*.[ch]" | xargs etags --append 