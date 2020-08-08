prog.exe: main.o solve10.o
	gcc -g main.o solve10.o -o prog.exe -lm
main.o: main.c head.h
	gcc -g -W -Wall -O3 -c main.c -lm
solve10.o: solve10.c head.h
	gcc -g -W -Wall -O3 -c solve10.c -lm
clean:
	rm -f main.o solve10.o prog.exe

