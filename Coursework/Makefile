CC=gcc
CFLAGS=-I
DEPS = langton.h, visualiser.h

%.o: %.c $(DEPS)
%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

all: langton.o visualiser.o main.c
	$(CC) -o ant main.c langton.o visualiser.o -lncursesw
#curses -lncursesw

langton.o: langton.c langton.h
	$(CC) -c langton.c

visualiser.o: visualiser.c visualiser.h
	$(CC) -c visualiser.c

#langton.o: langton.c 
#	$(CC) -c langton.c

#visualiser.o: visualiser.c 
#	$(CC) -c visualiser.c

library:
	
clean:
	rm langton.o visualiser.o ant


