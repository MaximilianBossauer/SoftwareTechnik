run_FMS: FMS_build
	./build/FMS

FMS_build: build ./build/main.o ./build/fms.o ./build/fms_data.o
	gcc ./build/main.o ./build/fms.o ./build/fms_data.o -o ./build/FMS -lm

./build/main.o: ./src/main.c build
	gcc -c ./src/main.c -o ./build/main.o

./build/fms.o: ./src/fms.c ./src/fms.h build
	gcc -c ./src/fms.c -o ./build/fms.o

./build/fms_data.o: ./src/fms_data.c ./src/fms.h build
	gcc -c ./src/fms_data.c -o ./build/fms_data.o

build:
	mkdir -p ./build

clean:
	rm -r build
