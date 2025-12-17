run_primcalc: primcalc_build
	./build/PrimeCalculator

#Linker:
primcalc_build: build ./build/PrimeCalculator.o
	gcc ./build/PrimeCalculator.o -o ./build/PrimeCalculator

#Compiler:
./build/PrimeCalculator.o: ./src/PrimeCalculator.c build
	gcc -c ./src/PrimeCalculator.c -o ./build/PrimeCalculator.o

build:
	mkdir ./build

clean:
	rm -r build