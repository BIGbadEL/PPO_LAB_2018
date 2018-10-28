CXX = g++
EXEC = main.exe
CXXFLAGS = -pedantic -Wall -MMD -MP -D DEBUG

SRC=$(wildcard *.cpp)
OBJS=$(SRC:.cpp=.o)
DEPS=$(SRC:.cpp=.d)

$(EXEC): $(OBJS)
	$(CXX) -o $(EXEC) $(OBJS) $(CXXFLAGS)

*.o: *.cpp
	$(CXX) -c $(CXXFLAGS) $<

.PHONY: clean run rebuild debug

rebuild:
	make clean
	make run

clean: 
	rm -f *.o
	rm -f  *.d
	rm -f *.exe

run: $(EXEC)
	./$(EXEC)




