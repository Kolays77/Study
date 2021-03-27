CFLAGS = -g -pg -Wall -W -Wextra -O3
a.out: solve.o main.o 
	g++ $(CFLAGS) solve.o main.o -o a.out -lm
solve.o: solve.cpp head.h
	g++ $(CFLAGS) -c solve.cpp
main.o: main.cpp head.h 
	g++ $(CFLAGS) -c main.cpp
clean:
	rm -f *.o *.out
