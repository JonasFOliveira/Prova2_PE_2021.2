out: main.o create.o 
	gcc -o out main.o create.o

main.o: main.c
	gcc -c main.c

clean.o: create.c create.h
	gcc -c clean.c

clean:
	rm *.o out