main:main.o test.o
	gcc $^ -o $@
%.o:%.c
	gcc -c $< -o $@
clean:
	rm *.o main