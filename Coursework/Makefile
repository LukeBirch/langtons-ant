CC=gcc
CFLAGS=-I
DEPS = langton.h, visualiser.h 
OBJ = langton.o visualiser.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

make all: visualiser.o langton.o main.c
	$(CC) -o ant main.c visualiser.o langton.o -lncursesw
	./ant LLR

langton.o: langton.c langton.h
	$(CC) -c langton.c

visualiser.o: visualiser.c visualiser.h
	$(CC) -c visualiser.c

library: 
	$(CC) -c -fPIC langton.c
	$(CC) -c -fPIC visualiser.c
	$(CC) -shared -o libant.so langton.o visualiser.o -lncursesw
clean:
	rm $(OBJ) ant
