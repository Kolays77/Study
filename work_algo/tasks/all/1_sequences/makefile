CFLAGS = -g -pg -Wall -W -Wextra -O3
a.out: main.o solve.o
	g++ $(CFLAGS) main.o solve.o -o a.out

solve.o: solve.cpp head.h
	g++ $(CFLAGS) -c solve.cpp
main.o: main.cpp head.h
	g++ $(CFLAGS) -c main.cpp
clean:
	rm -f a.out leak* gmon* *.o
