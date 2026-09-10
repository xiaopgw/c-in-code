thttpd.out:main.c thttpd.c custom_handle.c
	gcc -o $@ $^ -lpthread

work:work.c
	gcc $^ -lpthread -lmodbus -o $@

clean:
	rm -rf *.out
