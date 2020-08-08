CFLAGS = -g -Wall -W -Wextra
a.out: student.o main.o tree.o 
	g++ $(CFLAGS) student.o main.o tree.o  -o a.out
student.o: student.cpp student.h
	g++ $(CFLAGS) -c student.cpp
tree.o: tree.cpp tree.h
	g++ $(CFLAGS) -c tree.cpp
main.o: main.cpp tree.h
	g++ $(CFLAGS) -c main.cpp
	
clean:
	rm -f a.out *.o
