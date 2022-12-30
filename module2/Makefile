CXX = g++ -std=c++20
objects = main.o io.o
.PHONY: all clean # In case there are files named "all" or "clean"

all: module2_final

module2_final: $(objects)
	$(CXX) -o module2_final $(objects)

main.o: main.cpp
	$(CXX) -c main.cpp

io.o: io.cpp io.h
	$(CXX) -c io.cpp

clean:
	rm *.o module2_final

