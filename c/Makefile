CC=clang
CFLAGS=-g
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
	  $(CC) -o $@ $<

$(BINDIR)/mouse-events: $(OBJDIR)/mouse-events.o
	  $(CC) -o $@ $< -lX11

$(OBJDIR)/%.o: %.c
	  $(CC) -c -o $@ $< $(CFLAGS)
