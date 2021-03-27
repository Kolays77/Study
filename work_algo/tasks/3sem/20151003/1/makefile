prog.exe: student.o generate.o main.o read.o student_list.o solve.o
	g++ -g -Wall -W -O3 -Wextra student.o main.o read.o student_list.o solve.o generate.o -o prog.exe
student.o: student.cpp student.h
	g++ -g -Wall -W -O3 -Wextra -c student.cpp
generate.o: generate.cpp generate.h
	g++ -g -Wall -W -O3 -Wextra -c generate.cpp
student_list.o: student_list.cpp student_list.h student_node.h
	g++ -g -Wall -W -O3 -Wextra -c student_list.cpp
read.o: read.cpp read.h
	g++ -g -Wall -W -O3 -Wextra -c read.cpp
solve.o: solve.cpp solve.h
	g++ -g -Wall -W -O3 -Wextra -c solve.cpp
main.o: main.cpp solve.h read.h
	g++ -g -Wall -W -O3 -Wextra -c main.cpp
clean:
	rm -f prog.exe *.o
