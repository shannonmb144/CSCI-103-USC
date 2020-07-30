CC = g++
CFLAGS = -g -Wall -Wvla -Wshadow -Wunreachable-code  -Wno-sign-conversion -Wno-sign-compare -Wno-write-strings -fdiagnostics-color=always
#-Wconversion  // It's okay to not flag double to integer conversion

LDFLAGS =
FILTERSRC = filter.cpp bmplib.cpp
FILTEROBJ = $(FILTERSRC:.cpp=.o)

all: filter

filter: $(FILTEROBJ)
	$(CC) $(CFLAGS) $(FILTEROBJ) -o filter

.cpp.o:
	$(CC) $(CFLAGS) -O0 -g -c $<

bmplib.o : bmplib.h

filter.o : bmplib.h
                                         
clean:
	rm -f *.o filter

