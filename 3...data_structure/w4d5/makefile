main:main.o insert.o delete.o traverse.o seplist.o 
	gcc $^ -o $@
%.o:%.c
	gcc -c $< -o $@
clean:
	rm *.o