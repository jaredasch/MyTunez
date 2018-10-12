all: linked_list.o
	gcc -o out linked_list.o

linked_list.o: linked_list.c
	gcc -c linked_list.c

run:
	./out

clean:
	rm out
	rm *.o	
