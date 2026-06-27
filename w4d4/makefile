1:DeleteFromA.o 1.o InsertIntoA.o Show.o
	gcc $^ -o $@
%.o:%.c
	gcc -c $< -o $@
clean:
	rm *.o