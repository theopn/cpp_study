CXX = g++ -std=c++20
objects = module2_final.o io.o
.PHONY: all clean # In case there are files named "all" or "clean"

all: module2_final

module2_final: $(objects)
	$(CXX) -o module2_final $(objects)

module2_final.o: module2_final.cpp
	$(CXX) -c module2_final.cpp

io.o: io.cpp io.h
	$(CXX) -c io.cpp

clean:
	rm *.o module2_final

