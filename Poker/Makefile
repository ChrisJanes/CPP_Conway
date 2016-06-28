CC=g++
CFLAGS= -c -Wall
LDFLAGS=
SOURCES = main.cpp Conway.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=conway

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@