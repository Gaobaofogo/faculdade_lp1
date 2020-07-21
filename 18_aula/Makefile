COMPILER = g++
FLAGS = -Wall -std=c++11 -I include -g
PROGRAM_NAME = prog
CPP_FILES = $(wildcard src/*.cpp)

all: object_files
	$(COMPILER) $(FLAGS) -o $(PROGRAM_NAME) *.o

object_files:
	$(COMPILER) $(FLAGS) -c $(CPP_FILES) main.cpp

clean:
	rm -rf *.o
	rm $(PROGRAM_NAME)
