prog.exe: main.o read.o
	gcc -g main.o read.o -o prog.exe
main.o: main.c read.h 
	gcc -g -c main.c
read.o: read.c read.h
	gcc -g -c read.c
clean:
	rm -f main.o read.o prog.exe
