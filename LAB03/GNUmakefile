CXX = g++
EXEC = main.exe
CXXFLAGS = -pedantic -Wall -MMD -MP
LIBS = -lm

SRC1=$(wildcard *.cpp)
SRC2=$(wildcard src/*.cpp)
SRC=$(SRC1)+$(SRC2)

OBJS1=$(SRC2:src/=)

OBJS=$(SRC1:.cpp=.o) $(OBJS1:.cpp=.o)
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
