CC = gcc
CFLAGS = -Wall -g
client: client.o
	$(CC) $(CFLAGS) -o client client.o
client.o: client.c common.h
	$(CC) $(CFLAGS) -o client.o -c client.c
