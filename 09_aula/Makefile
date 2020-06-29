COMPILER = g++
FLAGS = -Wall -std=c++11 -I include
PROGRAM_NAME = prog

all: bin/main.o bin/App.o bin/Date.o bin/Diary.o bin/Hour.o bin/helper_time.o
  $(COMPILER) $(FLAGS) -o $(PROGRAM_NAME) ./bin/*.o

bin/helper_time.o: src/helper_time.cpp
  $(COMPILER) $(FLAGS) -c 
