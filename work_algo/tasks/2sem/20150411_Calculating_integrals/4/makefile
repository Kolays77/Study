prog.exe: main.o solve4.o
	gcc -g main.o solve4.o -o prog.exe -lm
main.o: main.c head.h
	gcc -g -W -Wall -O3 -c main.c -lm
solve4.o: solve4.c head.h
	gcc -g -W -Wall -O3 -c solve4.c -lm
clean:
	rm -f main.o solve4.o prog.exe

