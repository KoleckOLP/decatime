# Makefile for workingtime.exe with .o files

CC = gcc
CFLAGS = -Wall -Wextra -O2 -static
TARGET = realtime
SRC = realtime.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

# Compile .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link .o files into the executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJ)
