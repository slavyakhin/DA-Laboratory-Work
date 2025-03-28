CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -I.

# Executable name - solution

solution: main.o
	$(CXX) $(CXXFLAGS) -o $@ main.o

main: main.cpp pair.hpp date.hpp vector.hpp sort.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f *.o

.PHONY: all clean