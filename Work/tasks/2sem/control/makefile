prog.exe: functions.o calc_integral.o find_roots.o main.o
	gcc -g functions.o calc_integral.o find_roots.o main.o -o prog.exe -lm

functions.o: functions.c head.h
	gcc -g -W -Wall -O3 -c functions.c -lm
calc_integral.o: calc_integral.c head.h
	gcc -g -W -Wall -O3 -c calc_integral.c -lm
findroots.o: find_roots.c head.h
	gcc -g -W -Wall -O3 -c find_roots.c -lm
main.o: main.c head.h
	gcc -g -W -Wall -O3 -c main.c -lm
clean:
	rm -f functions.o calc_integral.o find_roots.o main.o prog.exe

