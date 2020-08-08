CFLAGS = -g -Wall -W -Wextra
a.out: student.o generate.o main.o read.o student_list.o solve4.o
	g++ $(CFLAGS) student.o generate.o main.o read.o student_list.o solve4.o -o a.out
student.o: student.cpp student.h
	g++ $(CFLAGS) -c student.cpp
generate.o: generate.cpp generate.h
	g++ $(CFLAGS) -c generate.cpp
student_list.o: student_list.cpp student_list.h student_node.h
	g++ $(CFLAGS) -c student_list.cpp
read.o: read.cpp read.h
	g++ $(CFLAGS) -c read.cpp
main.o: main.cpp solve.h read.h
	g++ $(CFLAGS) -c main.cpp
solve4.o: solve4.cpp solve.h
	g++ $(CFLAGS) -c solve4.cpp
	
clean:
	rm -f a.out *.o
