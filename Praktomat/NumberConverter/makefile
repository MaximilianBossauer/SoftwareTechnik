run_converter: converter_build
	./build/NumberConverter

#Linker:
converter_build: build ./build/NumberConverter.o
	gcc ./build/NumberConverter.o -o ./build/NumberConverter

#Compiler:
./build/NumberConverter.o: ./src/NumberConverter.c 
	gcc -c ./src/NumberConverter.c -o ./build/NumberConverter.o

build:
	mkdir ./build

clean:
	rm -r build