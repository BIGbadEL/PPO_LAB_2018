CXX = g++
EXEC = main.exe
CXXFLAGS = -pedantic -MMD -MP -Wall    -Wextra -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wuseless-cast

LIBS = -lm

SRC=$(wildcard *.cpp)
OBJS=$(SRC:.cpp=.o)
DEPS=$(SRC:.cpp=.d)

PCH_SRC = prec/pch.h
PCH_OUT = pch.h.gch

$(EXEC): $(OBJS) 
	$(CXX) $(LFLAGS) $+ -o $@


%.o: %.cpp $(PCH_OUT)
	$(CXX) $(CXXFLAGS) -include $(PCH_SRC) -c $< -o $@

$(PCH_OUT): $(PCH_SRC)
	g++ -o $(PCH_OUT) $(PCH_SRC)

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
