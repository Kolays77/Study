prog.exe: main.o read_matrix.o function.o
	gcc -g main.o read_matrix.o function.o -o prog.exe
main.o: main.c read_matrix.h head.h
	gcc -g -c main.c
read_matrix.o: read_matrix.c read_matrix.h
	gcc -g -c read_matrix.c
function.o: function.c head.h
	gcc -g -c function.c
clean:
	rm -f main.o read_matrix.o function.o prog.exe
