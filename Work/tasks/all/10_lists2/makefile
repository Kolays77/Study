CFLAGS = -g -Wall -W -Wextra -O3 
a.out: node2.o list2.o read2.o generate.o main2.o solve2.o
	g++ $(CFLAGS)  node2.o list2.o read2.o generate.o main2.o solve2.o -o a.out
node2.o: node2.cpp node2.h
	g++ $(CFLAGS) -c node2.cpp
list2.o: list2.cpp list2.h node2.h
	g++ $(CFLAGS) -c list2.cpp
generate.o: generate.cpp generate.h list2.h
	g++ $(CFLAGS) -c generate.cpp
read2.o: read2.cpp read2.h list2.h
	g++ $(CFLAGS) -c read2.cpp
main2.o: main2.cpp read2.h list2.h solve2.h
	g++ $(CFLAGS) -c main2.cpp
	
solve2.o: solve2.cpp solve2.h
	g++ $(CFLAGS) -c solve2.cpp
	
clean:
	rm -f a.out *.o leak*
