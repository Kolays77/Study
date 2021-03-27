prog.exe: student.o main.o read.o sort.o generate.o
	g++ -g -Wall -W -O3 -Wextra student.o main.o read.o sort.o generate.o -o prog.exe
student.o: student.cpp student.h
	g++ -g -Wall -W -O3 -Wextra -c student.cpp 
main.o: main.cpp read.h sort.h generate.h
	g++ -g -Wall -W -O3 -Wextra -c main.cpp
read.o: read.cpp read.h
	g++ -g -Wall -W -O3 -Wextra -c read.cpp
sort.o: sort.cpp sort.h read.h
	g++ -g -Wall -W -O3 -Wextra -c sort.cpp
generate.o: generate.cpp generate.h
	g++ -g -Wall -W -O3 -Wextra -c generate.cpp
clean:
	rm -f main.o read.o sort.o student.o generate.o prog.exe
