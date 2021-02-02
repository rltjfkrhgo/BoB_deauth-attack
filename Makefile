CC=g++
CFLAGS=-c
LDFLAGS=-lpcap
SOURCES=mac.cpp DeauthAttack.cpp DeauthAttackMain.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=deauth-attack

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o $(EXECUTABLE)
