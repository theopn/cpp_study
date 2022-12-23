CXX = g++ -std=c++20
objects = playground.o
.PHONY: all clean # In case there are files named "all" or "clean"

all: playground

playground: $(objects)
	$(CXX) -o playground $(objects)

playground.o: playground.cpp
	$(CXX) -c playground.cpp

clean:
	rm *.o playground

