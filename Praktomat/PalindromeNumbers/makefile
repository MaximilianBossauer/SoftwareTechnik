run_PaNum: PalindromeNumbers_build
	./build/PalindromeNumbers
#Linker:
PalindromeNumbers_build: build ./build/PalindromeNumbers.o
	gcc ./build/PalindromeNumbers.o -o ./build/PalindromeNumbers

#Compiler:
./build/PalindromeNumbers.o: ./src/PalindromeNumbers.c build
	gcc -c ./src/PalindromeNumbers.c -o ./build/PalindromeNumbers.o

build:
	mkdir ./build

clean:
	rm -r build