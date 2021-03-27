prog.exe: main.o solve.o
	gcc -g main.o solve.o -o prog.exe -lm
main.o: main.c head.h
	gcc -g -W -Wall -O3 -c main.c -lm
solve.o: solve.c head.h
	gcc -g -W -Wall -O3 -c solve.c -lm
clean:
	rm -f main.o solve.o prog.exe

