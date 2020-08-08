CFLAGS = -g -Wall -W -Wextra -O3 
a.out: node1.o list1.o read1.o generate.o main1.o solve1.o
	g++ $(CFLAGS)  node1.o list1.o read1.o generate.o main1.o solve1.o -o a.out
node1.o: node1.cpp node1.h
	g++ $(CFLAGS) -c node1.cpp
list1.o: list1.cpp list1.h node1.h
	g++ $(CFLAGS) -c list1.cpp
generate.o: generate.cpp generate.h list1.h
	g++ $(CFLAGS) -c generate.cpp
read1.o: read1.cpp read1.h list1.h
	g++ $(CFLAGS) -c read1.cpp
main1.o: main1.cpp read1.h list1.h solve1.h
	g++ $(CFLAGS) -c main1.cpp
	
solve1.o: solve1.cpp solve1.h
	g++ $(CFLAGS) -c solve1.cpp
	
clean:
	rm -f a.out *.o leak*
