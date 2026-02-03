CC = gcc
CFLAGS = -Wall
SRC = main.c
TARGET = main

.PHONY: all clean

all: $(SRC)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)
