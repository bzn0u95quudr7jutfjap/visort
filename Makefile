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
	./$(BIN) n=8 algo=bbs
	./$(BIN) n=8 algo=cts
	./$(BIN) n=8 algo=ezs
	./$(BIN) n=8 algo=inss
	./$(BIN) n=8 algo=sels
	./$(BIN) n=32 algo=qcs
	./$(BIN) n=32 algo=merge

test:build
	./$(BIN) n=20 algo=merge-iter
