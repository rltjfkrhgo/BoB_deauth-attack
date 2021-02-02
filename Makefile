CC=g++
CFLAGS=-c
LDFLAGS=-lpcap
SOURCES=DeauthAttackMain.cpp mac.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=deauth-attack

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o $(EXECUTABLE)
