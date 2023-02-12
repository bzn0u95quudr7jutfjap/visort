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
	./$(BIN) delay=20 n=20 algo=bbs
	./$(BIN) delay=20 n=20 algo=cts
	./$(BIN) delay=20 n=20 algo=ezs
	./$(BIN) delay=20 n=20 algo=inss
	./$(BIN) delay=20 n=20 algo=sels
	./$(BIN) delay=20 n=64 algo=qcs
	./$(BIN) delay=20 n=64 algo=merge
	./$(BIN) delay=20 n=64 algo=merge-iter

test:build
	./$(BIN) n=20 algo=merge-iter
