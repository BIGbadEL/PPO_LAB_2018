CXX = g++
CXXFLAGS = -g -Wall -pedantic -MMD -MP

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)

main.exe: $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o main.exe

*.o: *.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean run rebuild

clean: 
	rm -rf *.d
	rm -rf *.o
	rm -rf *.exe

run: main.exe
	./main.exe
	
rebuild:
	make clean
	make run

-include $(DEP)