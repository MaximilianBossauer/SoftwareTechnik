run_AC: AC_build
	./build/AtmosphericCalculations

#Linker:
AC_build: build ./build/AtmosphericCalculations.o
	gcc ./build/AtmosphericCalculations.o -o ./build/AtmosphericCalculations

#Compiler:
./build/AtmosphericCalculations.o: ./src/AtmosphericCalculations.c build
	gcc -c ./src/AtmosphericCalculations.c -o ./build/AtmosphericCalculations.o

build:
	mkdir ./build

clean:
	rm -r buil