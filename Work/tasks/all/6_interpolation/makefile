CFLAGS = -g -pg -Wall -W -Wextra -O3
a.out: solve.o read.o main.o 
	g++ $(CFLAGS) solve.o main.o read.o -o a.out -lm
solve.o: solve.cpp head.h
	g++ $(CFLAGS) -c solve.cpp
read.o: read.cpp read.h
	g++ $(CFLAGS) -c read.cpp
main.o: main.cpp head.h 
	g++ $(CFLAGS) -c main.cpp
clean:
	rm -f *.o *.out
