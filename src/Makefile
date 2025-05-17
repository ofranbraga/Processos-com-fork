CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11

all: fork_exec

fork_exec: fork_exec.c
	$(CC) $(CFLAGS) -o fork_exec fork_exec.c

clean:
	rm -f fork_exec