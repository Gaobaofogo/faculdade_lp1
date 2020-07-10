COMPILER = g++
FLAGS = -Wall -std=c++11 -I include -g
PROGRAM_NAME = supermercado
CPP_FILES = $(wildcard src/*.cpp)

all: object_files
	$(COMPILER) $(FLAGS) -o $(PROGRAM_NAME) *.o

object_files:
	$(COMPILER) $(FLAGS) -c $(CPP_FILES) main.cpp

test: test_objects
	$(COMPILER) $(FLAGS) -o $(PROGRAM_NAME)_test *.o

test_objects:
	$(COMPILER) $(FLAGS) -c -I include $(CPP_FILES) test/*.cpp

clean:
	rm -rf *.o
	rm -rf $(PROGRAM_NAME)
