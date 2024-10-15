# Compiler
CXX = clang++
CXXFLAGS = -std=c++17 -Wall -O2 -pg

# Targets
TARGETS = Q1 Q1Deque Q1M

all: $(TARGETS)

Q1: Q1.cpp
	$(CXX) $(CXXFLAGS) -o Q1 Q1.cpp

Q1Deque: Q1Deque.cpp
	$(CXX) $(CXXFLAGS) -o Q1Deque Q1Deque.cpp

Q1M: Q1M.cpp
	$(CXX) $(CXXFLAGS) -o Q1M Q1M.cpp

clean:
	rm -f $(TARGETS) gmon.out
