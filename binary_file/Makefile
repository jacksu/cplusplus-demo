CC=g++
CFLAGS=-Wall
LDFLAGS=
SRC=$(wildcard *.cpp)
OBJ=$(patsubst %.cpp,%.o,$(SRC))

OUTPUT=binary_file

all:$(OUTPUT)

%.o: %.cpp
		$(CC) $(CFLAGS) -c -o $@ $<

$(OUTPUT): $(OBJ)
		$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean

clean:
		rm -f $(OBJ) $(OUTPUT)
