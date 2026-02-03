CC = gcc
CFLAGS = -Wall
SRC = main.c
TARGET = main

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)
