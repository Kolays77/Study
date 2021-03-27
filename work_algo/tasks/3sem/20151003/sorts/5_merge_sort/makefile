HEADERS = $(wildcard *.h)
CFALGS := -g -Wall -c
LDFLAGS := -g -Wall
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
PROGRAM := prog

all: $(PROGRAM) $(OBJECTS)

$(PROGRAM): $(OBJECTS)
	g++ $(LDFLAGS) $(OBJECTS) -o $(PROGRAM)
%.o: %.c $(HEADERS)
	g++ $(CFLAGS) $<
clean:
	rm -f *.o
