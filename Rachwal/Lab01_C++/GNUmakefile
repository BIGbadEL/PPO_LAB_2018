CXX = g++
EXEC = main.exe
CXXFLAGS = -pedantic -Wall -MMD -MP -g -Wall -D DELETE
LIBS = -lm

SRC = include/StudentList.h src/StudentList.cpp src/StudentListOperations.cpp
OBJ = StudentList.o StudentListOperations.o Main.o

$(EXEC): $(OBJ)
	$(CXX) -o $(EXEC) $(CXXFLAGS) $(OBJ)
Main.o: Main.cpp
	$(CXX) -c Main.cpp $(CXXFLAGS)
StudentList.o: src/StudentList.cpp
	$(CXX) -c src/StudentList.cpp $(CXXFLAGS)
StudentListOperations.o: src/StudentListOperations.cpp
	$(CXX) -c src/StudentListOperations.cpp $(CXXFLAGS)

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
