CXX = g++
EXEC = main.exe
CXXFLAGS = -pedantic -MMD -MP -Wall  -g  -Wextra -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wuseless-cast
LIBS = -lm

SRC=$(wildcard *.cpp)
OBJS=$(SRC:.cpp=.o)
DEPS=$(SRC:.cpp=.d)

$(EXEC): $(OBJS) 
	$(CXX) $(LFLAGS) $+ -o $@

# pull in dependency info for *existing* .o files
#-include $(OBJS:.o=.d)

*.o: *.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean run rebuild

rebuild: 
	make clean
	make run

clean:
	rm -f *.o
	rm -f *~
	rm -f *.d
	rm -f $(EXEC)

run: $(EXEC)
	./$(EXEC)

-include $(DEPS)
