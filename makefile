# Makefile for Truth Table Evaluator
CC=g++
CFLAGS=-std=c++11 -Iinclude -Wall

PROGRAM=TruthTable.out

OBJECTS = \
	Parser/truthtable.tab.o \
	Parser/truthtable.yy.o \
	Main.o \
	TruthTable.o \
	Statement/TruthStatement.o \
	Statement/IdentifierStatement.o \
	Statement/LiteralStatement.o \
	Statement/UnaryOperator.o \
	Statement/UnaryStatement.o \
	Statement/BinaryOperator.o \
	Statement/BinaryStatement.o \
	Statement/StatementList.o


# Add the source directory
OBJECTS := $(OBJECTS:%=src/%)


all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CC) $^ -o $@

%.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

# Build the parser (using a Bison file)
%.tab.o: %.tab.cpp
%.tab.cpp: %.y
	bison -v --defines=$(@:%.cpp=%.h) -o $@ $<

# Build the lexer (using a Flex file)
%.yy.o: %.yy.cpp
%.yy.cpp: %.l
	flex --header-file=$(@:%.cpp=%.h) -o $@ $<



# Run the file
.PHONY: run
run: $(PROGRAM)
	./$(PROGRAM)

# Remove all files
.PHONY: clean
clean:
	rm -f $(PROGRAM) $(OBJECTS)
	rm -f src/Parser/truthtable.tab.cpp src/Parser/truthtable.yy.cpp
	rm -f src/Parser/truthtable.tab.h src/Parser/truthtable.yy.h
