CFLAGS=-O2 -Wall -Wextra -Werror -pedantic-errors
LDFLAGS=-lm
OBJECTS:=$(patsubst %.c,%.o,$(wildcard *.c))
.PHONY: all
all: myprogram
myprogram: $OBJECTS
%.o: %.c
