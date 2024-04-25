output: main.o rawMode.o
	gcc main.o rawMode.o -o output

main.o: main.c
	gcc -c main.c

rawMode.o: rawMode.c rawMode.h
	gcc -c rawMode.c

clean:
	rm *.o