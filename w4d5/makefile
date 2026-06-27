main:main.o insert.o delete.o traverse.o seplist.o seplist_insert.o seplist_delete.o seplist_traverse.o
	gcc $^ -o $@
%.o:%.c
	gcc -c $< -o $@
clean:
	rm *.o