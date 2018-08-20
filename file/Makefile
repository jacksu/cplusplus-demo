CC=g++
CFLAGS=-Wall -I../third-party/glog/include/
LDFLAGS=-L../third-party/glog/lib -Wl,-rpath ../third-party/glog/lib  -lglog
SRC=$(wildcard *.cpp)
OBJ=$(patsubst %.cpp,%.o,$(SRC))

OUTPUT=file_test 

all:$(OUTPUT)

%.o: %.cpp
		$(CC) $(CFLAGS) -c -o $@ $<

$(OUTPUT): $(OBJ)
		$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean

clean:
		rm -f $(OBJ) $(OUTPUT)
