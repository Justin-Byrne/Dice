# CONSTANTS
## General
CC=g++
C_FLAGS=-c
DEPS=Main.o DICE.o

## Output
O_LOCAT=bin/release/
O_FLAGS=-o
O_FILE=Dice

## Directories
SRC=src
INC=include

# CONDITIONALS
ifeq ($(OS),Windows_NT)
	CLEAN=del *.o
else
	CLEAN=rm -f *.o
endif

# COMMANDS
linux: $(DEPS)
	$(CC) $(DEPS) $(O_FLAGS) $(O_LOCAT)$(O_FILE).sh

win32: $(DEPS)
	$(CC) $(DEPS) $(O_FLAGS) $(O_LOCAT)$(O_FILE).exe

main.o: Main.cpp
	$(CC) $(C_FLAGS) Main.cpp

DICE.o: $(SRC)/DICE.cpp $(INC)/DICE.h
	$(CC) $(C_FLAGS) $(SRC)/DICE.cpp

clean:
	$(CLEAN)

## EXAMPLES
## $ make linux         (For Linux operating system)
## $ make clean
##
## > make win32         (For Windows operating system)
## > make clean