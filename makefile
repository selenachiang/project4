SHELL=/bin/bash
CXX=g++
CXXFLAGS=-std=c++11 -Wall -g
RM=rm -rf

.PHONY: clean

# Target rules
main: main.o patient.o patients.o #text-menu-app.o patients.o
	$(CXX) -o $@ $^

test: test.o patient.o patients.o
	$(CXX) -o $@ $^
	./test

# General compilation rules
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Rule to test run your code with the exact same input used in the sample run
test-run: main
	./main < input.txt

clean:
	$(RM) *.o main test *.gc* *.dSYM
