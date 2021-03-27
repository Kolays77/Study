prog.exe: main.o read_matrix2.o norm.o solve2.o
	gcc -g -Wall -O3 main.o read_matrix2.o norm.o solve2.o -o prog.exe -lm
main.o: main.c read_matrix.h head.h
	gcc -g -W -Wall -O3 -c main.c
norm.o: norm.c head.h
	gcc -g -W -Wall -O3 -c norm.c -lm
read_matrix2.o: read_matrix2.c read_matrix.h
	gcc -g -W -Wall -O3 -c read_matrix2.c
solve2.o: solve2.c head.h
	gcc -g -W -Wall -O3 -c solve2.c -lm
clean:
	rm -f main.o read_matrix2.o norm.o solve2.o prog.exe
