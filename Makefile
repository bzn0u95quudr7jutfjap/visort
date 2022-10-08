CC=g++
CFLAGS=-lSDL2

SRCD=src
OBJD=obj
SRCS=$(wildcard $(SRCD)/*.cpp)
OBJS=$(patsubst $(SRCD)/%.cpp, $(OBJD)/%.o, $(SRCS))
BIN=sorting

$(OBJD)/%.o:$(SRCD)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: build run clean

clean:
	rm -fr $(OBJD)/* $(BIN)

build:$(BIN)

run:build
	./$(BIN) 20 bbs
	./$(BIN) 20 cts
	./$(BIN) 20 ezs
	./$(BIN) 20 inss
	./$(BIN) 20 sels
	./$(BIN) 80 qcs
	./$(BIN) 80 merge
