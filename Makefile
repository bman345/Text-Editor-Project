output: main.o rawMode.o input.o
	gcc main.o rawMode.o input.o -o output

main.o: main.c
	gcc -c main.c

rawMode.o: rawMode.c rawMode.h
	gcc -c rawMode.c

input.o: input.c input.h
	gcc -c input.c

clean:
	rm *.o output