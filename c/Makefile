#CC=gcc
CC=clang

###############################################################################
# from greyfade
###############################################################################
# -Wall -Wextra -Werror -pedantic-errors
###############################################################################
# from DWD
# -Wno-unused-argument -Wno-unused-variable
###############################################################################
# from coding cave
###############################################################################
#CFLAGS=-Wall -Wpedantic -Werror -Wshadow -Wformat=2 -Wconversion -Wunused-parameter -fsanitize=address,undefined
# without -Werror
#CFLAGS=-Wall -Wpedantic -Wshadow -Wformat=2 -Wconversion -Wunused-parameter -fsanitize=address,undefined
###############################################################################
# -std=c11
# -std=gnu99
###############################################################################
#CFLAGS=-g -Wall -Wpedantic -Wshadow -Wformat=2 -Wconversion -Wunused-parameter -Wextra -fsanitize=address,undefined
CFLAGS=-g -Wall -Wpedantic -Wshadow -Wformat=2 -Wconversion -Wunused-parameter
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
