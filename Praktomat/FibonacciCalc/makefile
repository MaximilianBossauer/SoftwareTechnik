run_fibocalc: fibocalc_build
	./build/FibonacciCalculator

#Linker:
fibocalc_build: build ./build/FibonacciCalculator.o
	gcc ./build/FibonacciCalculator.o -o ./build/FibonacciCalculator

#Compiler:
./build/FibonacciCalculator.o: ./src/FibonacciCalculator.c build
	gcc -c ./src/FibonacciCalculator.c -o ./build/FibonacciCalculator.o

build:
	mkdir ./build

clean:
	rm -r build