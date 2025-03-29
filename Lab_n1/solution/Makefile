CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -I.

# Executable name - solution

all: main.o
	$(CXX) $(CXXFLAGS) -g -o solution main.o

main.o: main.cpp pair.hpp date.hpp vector.hpp sort.hpp
	$(CXX) $(CXXFLAGS) -g -c main.cpp

clean:
	rm main.o

.PHONY: all main.o clean