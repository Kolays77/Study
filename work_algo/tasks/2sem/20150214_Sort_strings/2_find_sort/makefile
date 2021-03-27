prog.exe: main.o read.o sort.o
	gcc -g main.o read.o sort.o prog.exe
main.o: main.c read.h sort.h
	gcc -g -c main.c
read.o: read.c read.h
	gcc -g -c read.c
sort.o: sort.c sort.h
	gcc -g -c sort.c
clean:
	rm -f main.o read.o sort.o prog.exe
