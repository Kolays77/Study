prog.exe: main.o solve9.o
	gcc -g main.o solve9.o -o prog.exe -lm
main.o: main.c head.h
	gcc -g -W -Wall -O3 -c main.c -lm
solve9.o: solve9.c head.h
	gcc -g -W -Wall -O3 -c solve9.c -lm
clean:
	rm -f main.o solve9.o prog.exe

