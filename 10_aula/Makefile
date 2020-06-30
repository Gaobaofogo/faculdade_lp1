COMPILER = g++
FLAGS = -Wall -std=c++11 -I include
PROGRAM_NAME = prog
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
	rm *.o
	rm $(PROGRAM_NAME)
