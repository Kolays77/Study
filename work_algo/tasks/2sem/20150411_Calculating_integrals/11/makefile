prog.exe: main.o solve11.o
	gcc -g main.o solve11.o -o prog.exe -lm
main.o: main.c head.h
	gcc -g -W -Wall -O3 -c main.c -lm
solve11.o: solve11.c head.h
	gcc -g -W -Wall -O3 -c solve11.c -lm
clean:
	rm -f main.o solve11.o prog.exe

