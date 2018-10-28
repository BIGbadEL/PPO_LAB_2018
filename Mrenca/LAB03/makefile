CXX = g++
CXXFLAG = -g -Wall -pedantic

main.exe: lab03.o table_functions.o
	$(CXX) $(CXXFLAG) lab03.o table_functions.o -o main.exe
lab03.o: lab03.cpp
	$(CXX) $(CXXFLAG) -c lab03.cpp
table_functons.o: table_functions.cpp table_functions.h
	$(CXX) $(CXXFLAG) -c table_functions.cpp

.PHONY: clean run rebuild

rebuild:
	make clean
	make run

run: main.exe
	./main.exe

clean:
	rm -f main.exe
	rm -f *.o
