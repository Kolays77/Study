CFLAGS = -g -Wall -W -Wextra
a.out: student.o generate.o main.o read.o tree.o solve1.o solve2.o solve3.o solve4.o solve5.o
	g++ $(CFLAGS) student.o generate.o main.o read.o tree.o solve1.o solve2.o solve3.o solve4.o solve5.o -o a.out
student.o: student.cpp student.h
	g++ $(CFLAGS) -c student.cpp
generate.o: generate.cpp read.h
	g++ $(CFLAGS) -c generate.cpp
tree.o: tree.cpp tree_node.h tree.h
	g++ $(CFLAGS) -c tree.cpp
read.o: read.cpp read.h
	g++ $(CFLAGS) -c read.cpp
main.o: main.cpp read.h
	g++ $(CFLAGS) -c main.cpp
	
solve1.o: solve1.cpp solve.h
	g++ $(CFLAGS) -c solve1.cpp
solve2.o: solve2.cpp solve.h
	g++ $(CFLAGS) -c solve2.cpp
solve3.o: solve3.cpp solve.h
	g++ $(CFLAGS) -c solve3.cpp
solve4.o: solve4.cpp solve.h
	g++ $(CFLAGS) -c solve4.cpp
solve5.o: solve5.cpp solve.h
	g++ $(CFLAGS) -c solve5.cpp
	
clean:
	rm -f a.out b.txt *.o
