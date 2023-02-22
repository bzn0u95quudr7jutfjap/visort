CC=g++
CFLAGS=-lSDL2

SRCD=src
OBJD=obj
SRCS=$(wildcard $(SRCD)/*.cpp)
OBJS=$(patsubst $(SRCD)/%.cpp, $(OBJD)/%.o, $(SRCS))
BIN=sorting

$(OBJD):
	mkdir -p $@

$(OBJD)/%.o:$(SRCD)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: build run clean

clean:
	rm -fr $(OBJS) $(BIN)

build:$(OBJD) $(BIN)

run:build
	./$(BIN) n=100 algo=bubble
	./$(BIN) n=100 algo=cocktail
	./$(BIN) n=100 algo=easy
	./$(BIN) n=100 algo=insertion
	./$(BIN) n=100 algo=selection
	./$(BIN) n=200 algo=quick
	./$(BIN) n=200 algo=merge
	./$(BIN) n=200 algo=merge-iter
	./$(BIN) n=200 algo=merge-iter-post
	./$(BIN) n=200 algo=merge-inplace
	./$(BIN) n=200 algo=merge-inplace-iter

all:build best random worst
