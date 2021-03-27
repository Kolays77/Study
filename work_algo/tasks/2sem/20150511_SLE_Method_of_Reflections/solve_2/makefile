prog.exe: main.o read_matrix.o norm.o solve.o
	gcc -g main.o read_matrix.o norm.o solve.o -o prog.exe -lm
main.o: main.c read_matrix.h head.h
	gcc -g -W -Wall -O3 -c main.c
norm.o: norm.c head.h
	gcc -g -W -Wall -O3 -c norm.c -lm
read_matrix.o: read_matrix.c read_matrix.h
	gcc -g -W -Wall -O3 -c read_matrix.c
solve.o: solve.c head.h
	gcc -g -W -Wall -O3 -c solve.c -lm
clean:
	rm -f main.o read_matrix.o norm.o prog.exe
