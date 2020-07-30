CC=g++
CFLAGS= -Wall -g
LDFLAGS=

TARGET=pagerank
CPP_FILES=$(wildcard *.cpp)
OBJS=${CPP_FILES:%.cpp=%.o}

all: $(TARGET)


%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<    

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean: 
	rm -f *.o pagerank
