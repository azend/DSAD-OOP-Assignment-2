
CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp DoorBot.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Doorbot

all: $(SOURCES) $(EXECUTABLE)

clean: $(EXECUTABLE)
	-rm $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
