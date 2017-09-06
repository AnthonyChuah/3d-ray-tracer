COMPILER_FLAGS = -Wall -g -c -std=c++11

Main: Main.o
	g++ Main.o -o Main

Main.o: Grid.hpp Point.hpp
	g++ $(COMPILER_FLAGS) Main.cpp

clean:
	rm -rf Main *.o
