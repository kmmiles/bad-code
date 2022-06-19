#CC=gcc
CC=clang

###############################################################################
# from coding cave
CFLAGS=-g -Wall -Wpedantic -Werror -Wshadow -Wformat=2 -Wconversion -Wunused-parameter
#CFLAGS=-g -Wall -Wpedantic -Wshadow -Wformat=2 -Wconversion -Wunused-parameter
###############################################################################
#CFLAGS=-Weverything -Wall -Wpedantic -Werror -Wextra -std=c11
#CFLAGS=-Wall -Werror -Wextra -Wpedantic -MMD -std=gnu99 -g 
#CFLAGS=-g -Wall -Wpedantic -Werror -std=c11
#CFLAGS=-Wall -Wpedantic -Wextra -Wunused-parameter -std=c11
LIBS=-lm 
#-lcriterion
DIRS=obj bin
OBJDIR=obj
BINDIR=bin
SRC=$(wildcard *.c)
OBJS=$(patsubst %.c, $(OBJDIR)/%.o, $(SRC))
BINS=$(patsubst %.c, $(BINDIR)/%, $(SRC))

.PHONY: all
all: mkdirs bins

.PHONY: mkdirs
mkdirs:
	@mkdir -p $(DIRS)

.PHONY: clean
clean:
	@rm -rf $(DIRS)

bins: $(BINS)
objs: $(OBJS)

$(BINDIR)/%: $(OBJDIR)/%.o
	  $(CC) -o $@ $< $(LIBS)

$(BINDIR)/mouse-events: $(OBJDIR)/mouse-events.o
	  $(CC) -o $@ $< $(LIBS) -lX11

$(BINDIR)/clear: $(OBJDIR)/clear.o
	  $(CC) -o $@ $< $(LIBS) -lncurses

$(BINDIR)/hello-curses: $(OBJDIR)/hello-curses.o
	  $(CC) -o $@ $< $(LIBS) -lncurses

$(OBJDIR)/%.o: %.c
	  $(CC) -c -o $@ $< $(CFLAGS)
