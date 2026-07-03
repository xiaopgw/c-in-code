main:main.o sequential.o
	gcc $^ -o $@
%.o:%.c
	gcc -c $< -o $@
clean:
	rm *.o main.c