CC = gcc

CFLAGS = -Wall -Wextra -g

EXEC = chash

SRC = chash.c

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $(EXEC) $(SRC)

run: all
	./$(EXEC)

clean:
	rm -f $(EXEC)