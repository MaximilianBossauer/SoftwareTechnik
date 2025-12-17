run_fd: fd_build
	./build/FlightDistance

#Linker:
fd_build: build ./build/FlightDistance.o
	gcc ./build/FlightDistance.o -o ./build/FlightDistance

#Compiler:
./build/FlightDistance.o: ./src/FlightDistance.c build
	gcc -c ./src/FlightDistance.c -o ./build/FlightDistance.o

build:
	mkdir ./build

clean:
	rm -r build