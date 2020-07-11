COMPILER = g++
FLAGS = -Wall -std=c++11 -I include -g
PROGRAM_NAME = supermercado
CPP_FILES = $(wildcard src/*.cpp)

all: object_files
	$(COMPILER) $(FLAGS) -o $(PROGRAM_NAME) *.o

object_files:
	$(COMPILER) $(FLAGS) -c $(CPP_FILES) main.cpp

clean:
	rm -rf *.o
	rm -rf $(PROGRAM_NAME)
	rm -rf cliente_*.txt
