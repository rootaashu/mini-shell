
CC = gcc
CFLAGS = -Wall -Wextra -g
SRC = src/shell.c src/history.c
TARGET = minishell
LIBS = -lreadline

all:
	$(CC) $(CFLAGS) $(SRC) $(LIBS) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean

