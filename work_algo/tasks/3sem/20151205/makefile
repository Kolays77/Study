CFLAGS = -g -Wall -W -Wextra -lm
a.out: student.o generate.o main.o read.o stack.o queue.o tree.o menu.o
	g++ $(CFLAGS) student.o generate.o main.o read.o stack.o queue.o tree.o menu.o -o a.out
	
student.o: student.cpp student.h
	g++ $(CFLAGS) -c student.cpp
generate.o: generate.cpp read.h
	g++ $(CFLAGS) -c generate.cpp
stack.o: stack.cpp stack_node.h stack.h
	g++ $(CFLAGS) -c stack.cpp
read.o: read.cpp read.h
	g++ $(CFLAGS) -c read.cpp
queue.o: queue.cpp queue.h queue_node.h
	g++ $(CFLAGS) -c queue.cpp
tree.o: tree.cpp tree_node.h tree.h
	g++ $(CFLAGS) -c tree.cpp
main.o: main.cpp read.h
	g++ $(CFLAGS) -c main.cpp
	
menu.o: menu.cpp stack.h stack_of_tree_node.h
	g++ $(CFLAGS) -c menu.cpp
clean:
	rm -f a.out leak.out* *.o
