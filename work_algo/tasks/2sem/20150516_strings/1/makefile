prog.exe: main.o functions.o
	gcc -g -W -Wextra -O3 main.o functions.o -o prog.exe
main.o: main.c head.h 
	gcc -g -W -Wextra -O3 -c main.c
functions.o: functions.c head.h
	gcc -g -W -Wextra -O3 -c functions.c
clean:
	rm -f main.o functions.o prog.exe
