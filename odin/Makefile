DIRS=bin
BINDIR=bin
SRC=$(wildcard *.odin)
BINS=$(patsubst %.odin, $(BINDIR)/%, $(SRC))

.PHONY: all
all: mkdirs bins

.PHONY: mkdirs
mkdirs:
	@mkdir -p $(DIRS)

.PHONY: clean
clean:
	@rm -rf $(DIRS)

bins: $(BINS)

$(BINDIR)/%: %.odin
		odin build $< -out:$@
