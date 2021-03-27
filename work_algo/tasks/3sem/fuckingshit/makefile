CFLAGS = -g -Wall -W -Wextra
a.out: student.o generate.o main.o read.o student_list.o queue.o
	g++ $(CFLAGS) student.o generate.o main.o read.o student_list.o queue.o -o a.out
student.o: student.cpp student.h
	g++ $(CFLAGS) -c student.cpp
generate.o: generate.cpp read.h
	g++ $(CFLAGS) -c generate.cpp
student_list.o: student_list.cpp student_node.h student_list.h
	g++ $(CFLAGS) -c student_list.cpp
read.o: read.cpp read.h
	g++ $(CFLAGS) -c read.cpp
queue.o: queue.cpp queue.h
	g++ $(CFLAGS) -c queue.cpp
main.o: main.cpp read.h
	g++ $(CFLAGS) -c main.cpp
	
	
clean:
	rm -f a.out leak.out* *.o
