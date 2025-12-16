run_rechner: rechner_build
	./build/Tutorium_07_Rechner

#Linker:
rechner_build: build ./build/Tutorium_07_Rechner.o 
	gcc ./build/Tutorium_07_Rechner.o -o ./build/Tutorium_07_Rechner

#Compiler:
./build/Tutorium_07_Rechner.o: ./src/Tutorium_07_Rechner.c
	gcc -c ./src/Tutorium_07_Rechner.c -o ./build/Tutorium_07_Rechner.o

build:
	mkdir ./build

clean:
	rm -r build

