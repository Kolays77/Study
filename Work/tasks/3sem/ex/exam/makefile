FLAGS = -Wall -O3 -g

a.out:  tmain.o tree.o fun.o
	g++ $(FLAGS) tmain.o tree.o fun.o

tmain.o:  tmain.cpp tree.h
	g++ -c $(FLAGS) -o tmain.o tmain.cpp

fun.o :  fun.cpp tree.h
	g++ -c $(FLAGS) -o fun.o fun.cpp

clean :
	rm tmain.o myfun.o a.out
