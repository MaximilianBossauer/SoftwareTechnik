run_digits: digits_build
	./build/Digits

#Linker: 
digits_build: build ./build/Digits.o
	gcc ./build/Digits.o -o ./build/Digits

#Compiler:
./build/Digits.o: ./src/Digits.c build
	gcc -c ./src/Digits.c -o ./build/Digits.o

build:
	mkdir ./build

clean:
	rm -r build