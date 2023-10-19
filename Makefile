# Makefile for deleting a file on Windows
CC = gcc
CFLAGS = -Wall -Wextra

# Define source files here
SRCS = Stack.c

# Define the name of the executable
EXEC = main.exe

$(EXEC): $(SRCS)
	$(CC) $(CFLAGS) -o $(EXEC) $(SRCS)

.PHONY: clean

# Clean operation
clean:
	del $(EXEC)  # Command to delete a file on Windows

# Add a target
run: $(EXEC)
	./$(EXEC)

.DEFAULT_GOAL := run