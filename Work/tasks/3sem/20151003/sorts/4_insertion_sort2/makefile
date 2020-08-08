CFLAGS = -g -Wall -W -Wextra -O3
a.out: student.o generate.o main.o read.o student_list.o sort.o
	g++ $(CFLASG) student.o main.o read.o student_list.o sort.o generate.o -o a.out
student.o: student.cpp student.h
	g++ $(CFLASG)-c student.cpp
generate.o: generate.cpp generate.h
	g++ $(CFLASG)-c generate.cpp
student_list.o: student_list.cpp student_list.h student_node.h
	g++ $(CFLASG)-c student_list.cpp
read.o: read.cpp read.h
	g++ $(CFLASG)-c read.cpp
sort.o: sort.cpp sort.h
	g++ $(CFLASG)-c sort.cpp
main.o: main.cpp sort.h read.h
	g++ $(CFLASG)-c main.cpp
clean:
	rm -f a.out *.o
