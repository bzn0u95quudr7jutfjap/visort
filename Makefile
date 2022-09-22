CC=g++
CFLAGS=-lSDL2

SRC=bbs.cpp sels.cpp cts.cpp ezs.cpp main.cpp qcs.cpp util.cpp bgo.cpp inss.cpp
OBJ=$(foreach i,$(basename $(SRC)), $(i).o  )
BIN=sorting

%.o:%.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

$(BIN):$(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: build run clean

clean:
	rm -fr $(OBJ) $(BIN)

build:$(BIN)

run:build
	./$(BIN) 14 bbs
	./$(BIN) 20 cts
	./$(BIN) 20 ezs
	./$(BIN) 20 inss
	./$(BIN) 80 qcs
	./$(BIN) 120 sels
