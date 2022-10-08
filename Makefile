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
	./$(BIN) 16 bbs
	./$(BIN) 16 cts
	./$(BIN) 16 ezs
	./$(BIN) 16 inss
	./$(BIN) 16 sels
	./$(BIN) 64 qcs
	./$(BIN) 64 merge

test:build
	./$(BIN) 08 bbs cts ezs inss sels qcs merge
