prog.exe: main.o solve8.o
	gcc -g main.o solve8.o -o prog.exe -lm
main.o: main.c head.h
	gcc -g -W -Wall -O3 -c main.c -lm
solve8.o: solve8.c head.h
	gcc -g -W -Wall -O3 -c solve8.c -lm
clean:
	rm -f main.o solve8.o prog.exe

