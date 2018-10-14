all: driver.o linked_list.o
	gcc -o out driver.o linked_list.o

driver.o: driver.c linked_list.h
	gcc -c driver.c

linked_list.o: linked_list.c
	gcc -c linked_list.c

run:
	./out

clean:
	rm out
	rm *.o
