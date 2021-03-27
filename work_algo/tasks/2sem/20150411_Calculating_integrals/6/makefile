prog.exe: main.o solve6.o
	gcc -g main.o solve6.o -o prog.exe -lm
main.o: main.c head.h
	gcc -g -W -Wall -O3 -c main.c -lm
solve6.o: solve6.c head.h
	gcc -g -W -Wall -O3 -c solve6.c -lm
clean:
	rm -f main.o solve6.o prog.exe

