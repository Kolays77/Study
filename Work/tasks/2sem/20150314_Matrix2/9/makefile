prog.exe: main.o read_matrix.o read_vector.o function.o
	gcc -g main.o read_matrix.o read_vector.o function.o -o prog.exe
main.o: main.c read_vector.h read_matrix.h head.h
	gcc -g -W -Wall -O3 -c main.c
read_vector.o: read_vector.c read_vector.h
	gcc -g -W -Wall -O3 -c read_vector.c
read_matrix.o: read_matrix.c read_matrix.h
	gcc -g -W -Wall -O3 -c read_matrix.c
function.o: function.c head.h
	gcc -g -W -Wall -O3 -c function.c
clean:
	rm -f main.o read_matrix.o read_vector.o function.o prog.exe

