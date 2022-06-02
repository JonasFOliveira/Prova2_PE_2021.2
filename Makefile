out: main.o create.o acess.o aggregation.o arithmetic.o dimensions.o 
	gcc -o out main.o create.o acess.o aggregation.o arithmetic.o dimensions.o

main.o: main.o header.h
	gcc -c main.c 

acess.o: acess.o header.h
	gcc -c acess.c

aggregation.o: aggregation.o header.h
	gcc -c aggregation.c 

arithmetic.o: arithmetic.o header.h
	gcc -c arithmetic.c

create.o: create.o header.h
	gcc -c create.c

dimensions.o: dimensions.o header.h
	gcc -c dimensions.c 



clean:
	rm *.o out