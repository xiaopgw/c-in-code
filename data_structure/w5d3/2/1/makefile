main:main.o linkedstack.o
	gcc $^ -o $@
%.o:%.c
	gcc -c $< -o $@
clean:
	rm *.o