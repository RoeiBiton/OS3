# Compiler
CXX = clang++
CXXFLAGS = -std=c++17 -Wall -O2

# Targets
TARGETS = Q1 Q1Deque

all: $(TARGETS)

Q1: Q1.cpp
	$(CXX) $(CXXFLAGS) -o Q1 Q1.cpp

Q1Deque: Q1Deque.cpp
	$(CXX) $(CXXFLAGS) -o Q1Deque Q1Deque.cpp

clean:
	rm -f $(TARGETS)
