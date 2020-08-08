prog.exe: main.o solve7.o
	gcc -g main.o solve7.o -o prog.exe -lm
main.o: main.c head.h
	gcc -g -W -Wall -O3 -c main.c -lm
solve7.o: solve7.c head.h
	gcc -g -W -Wall -O3 -c solve7.c -lm
clean:
	rm -f main.o solve7.o prog.exe

