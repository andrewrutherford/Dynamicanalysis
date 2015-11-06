# Andy Sayler
# Make Demo
# Summer 2014

CC = gcc
CFLAGS = -c -g -Wall -Wextra
LFLAGS = -Wall -Wextra

.PHONY: all clean

all: pi

pi: pi.o
	$(CC) $(LFLAGS) $^ -lm -o $@

pi.o: pi.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) *.o
	$(RM) pi
	$(RM) *~
