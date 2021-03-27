prog.exe: main.o read.o solve.o
	gcc -g main.o read.o solve.o -o prog.exe
main.o: main.c read.h head.h
	gcc -g -W -Wall -O3 -c main.c
read.o: read.c read.h
	gcc -g -W -Wall -O3 -c read.c
solve.o: solve.c head.h
	gcc -g -W -Wall -O3 -c solve.c
clean:
	rm -f main.o read.o solve.o prog.exe

