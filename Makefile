
CC=gcc
CFLAGS=-W -Wall -pedantic -std=c99 -Wstrict-aliasing=3 -O3 -fstrict-aliasing
LDFLAGS=

EXEC=aliasing

.PHONY: clean clean-all emacs-clean

all: $(EXEC)


$(EXEC): main.o test.o test.h
	$(CC) $(LDFLAGS) -o $(EXEC) main.o test.o
main.o: main.c test.h
	$(CC) $(CFLAGS) -c main.c -o main.o
test.o: test.c test.h
	$(CC) $(CFLAGS) -c test.c -o test.o


clean:
	rm -f *.o
emacs-clean:
	rm -f *~
	rm -f \#*
	rm -f *\#
clean-all: clean emacs-clean
	rm -f $(EXEC)
