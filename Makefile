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
	./$(BIN) 08 bbs
	./$(BIN) 08 cts
	./$(BIN) 08 ezs
	./$(BIN) 08 inss
	./$(BIN) 08 sels
	./$(BIN) 08 qcs
	./$(BIN) 08 merge
