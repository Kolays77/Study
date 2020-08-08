CFLAGS = -g -Wall -W -Wextra
a.out: student.o generate.o main.o read.o student_list.o solve1.o solve2.o solve3.o solve4.o solve5.o solve6.o solve7.o solve8.o solve9.o
	g++ $(CFLAGS) student.o generate.o main.o read.o student_list.o solve1.o solve2.o solve3.o solve4.o solve5.o solve6.o solve7.o solve8.o solve9.o -o a.out
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
solve6.o: solve6.cpp solve.h
	g++ $(CFLAGS) -c solve6.cpp
solve7.o: solve7.cpp solve.h
	g++ $(CFLAGS) -c solve7.cpp
solve8.o: solve8.cpp solve.h
	g++ $(CFLAGS) -c solve8.cpp
solve9.o: solve9.cpp solve.h
	g++ $(CFLAGS) -c solve9.cpp
	
clean:
	rm -f a.out *.o
