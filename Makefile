# name of the executable
EXE := fizzbuzz
# name of source and object directories
EXT := *.c
SDIR := src
ODIR := obj
# rules for making the object and the executable files
SOURCES := $(notdir $(wildcard $(SDIR)/$(EXT)))
SOURCE := $(patsubst %,$(SDIR)/%,$(SOURCES))
_OBJ := $(SOURCES:.c=.o)
OBJ := $(patsubst %,$(ODIR)/%,$(_OBJ))
PATHS := obj
# compiler
CC := gcc
# default C compiler flags
CCFLAGS := -D _DEFAULT_SOURCE -std=c99 -W -Wall -Wpedantic

ifndef DEBUG
CCFLAGS += -O3
endif
ifdef DEBUG
CCFLAGS += -g
endif
ifdef NUMBER
CCFLAGS += -DNUMBER=1
endif
ifdef SLEEP
CCFLAGS += -DSLEEP=1
endif
LDFLAGS := -O3

all : $(EXE)

$(EXE) : $(OBJ)
	$(CC) -o $(EXE) $(CCFLAGS) $(LDFLAGS) $(OBJ)
$(ODIR)/%.o : $(SDIR)/%.c $(PATHS)
	$(CC) $(CCFLAGS) -c -o $@ $<
$(PATHS) :
	if ! [ -d obj ]; then mkdir -p obj; fi
.PHONY : clean
clean:
	rm -rf $(OBJ) $(EXE) $(PATHS)
