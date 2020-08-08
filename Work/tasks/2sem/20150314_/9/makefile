prog.exe: main.o matrix.o solve.o
	gcc -g main.o matrix.o solve.o -o prog.exe
main.o: main.c matrix.h solve.h
	gcc -c -g main.c
matrix.o: matrix.c matrix.h
	gcc -c -g matrix.c
solve.o: solve.c solve.h
	gcc -g -c solve.c
