CC = g++
CFLAGS = -g -Wall -Wvla -Wshadow -Wunreachable-code -Wconversion -Wno-sign-conversion -Wno-sign-compare -Wno-write-strings -fdiagnostics-color=always

all:
	$(CC) $(CFLAGS) filesys.cpp mlist.cpp os.cpp -o filesys

clean:
	rm -f *.o filesys