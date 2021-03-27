prog.exe: main.o read.o function.o
	gcc -g main.o read.o function.o -o prog.exe
main.o: main.c read.h head.h
	gcc -g -c main.c
read.o: read.c read.h
	gcc -g -c read.c
function.o: function.c head.h
	gcc -g -c function.c
clean:
	rm -f main.o read.o function.o prog.exe
