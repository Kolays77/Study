prog.exe: main.o solve5.o
	gcc -g main.o solve5.o -o prog.exe -lm
main.o: main.c head.h
	gcc -g -W -Wall -O3 -c main.c -lm
solve5.o: solve5.c head.h
	gcc -g -W -Wall -O3 -c solve5.c -lm
clean:
	rm -f main.o solve5.o prog.exe

