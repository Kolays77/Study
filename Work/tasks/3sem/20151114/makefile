CFLAGS = -g -Wall -W -Wextra -O3
a.out: student.o main.o read.o tree.o 
	g++ $(CFLAGS) student.o main.o read.o tree.o  -o a.out
student.o: student.cpp student.h
	g++ $(CFLAGS) -c student.cpp
tree.o: tree.cpp tree_node.h tree.h
	g++ $(CFLAGS) -c tree.cpp
read.o: read.cpp read.h
	g++ $(CFLAGS) -c read.cpp
main.o: main.cpp read.h
	g++ $(CFLAGS) -c main.cpp
	
clean:
	rm -f a.out b.txt *.o
