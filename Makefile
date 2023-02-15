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
	./$(BIN) algo=bbs
	./$(BIN) algo=cts
	./$(BIN) algo=ezs
	./$(BIN) algo=inss
	./$(BIN) algo=sels
	./$(BIN) algo=qcs
	./$(BIN) algo=merge
	./$(BIN) algo=merge-iter

quick:build
	./$(BIN) delay=4 n=400 algo=qcs case=random border=0

best:build
	./$(BIN) delay=16 n=16 algo=bbs,cts,ezs,inss,sels,qcs,merge,merge-iter case=best
                                                                                       
worst:build                                                                            
	./$(BIN) delay=16 n=16 algo=bbs,cts,ezs,inss,sels,qcs,merge,merge-iter case=worst
                                                                                       
random:build                                                                           
	./$(BIN) delay=16 n=16 algo=bbs,cts,ezs,inss,sels,qcs,merge,merge-iter case=random

all:build best random worst
