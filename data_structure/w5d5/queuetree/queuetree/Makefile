CC = gcc
CFLAGS = -g -Wall

main:main.o linkqueue.o bitree.o
	$(CC) $(CFLAGS) -o $@ $^

.o:.c
	$(CC) -c $<

.PHONY:clean

clean:
	rm *.o main 
