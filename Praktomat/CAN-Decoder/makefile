run_CAN_DC: CAN_DC
	./build/Can_Decoder

#Linker:
CAN_DC: build ./build/Can_Decoder.o
	gcc ./build/Can_Decoder.o -o ./build/Can_Decoder

#Compiler:
./build/Can_Decoder.o: ./src/Can_Decoder.c build
	gcc -c ./src/Can_Decoder.c -o ./build/Can_Decoder.o

build:
	mkdir ./build

clean:
	rm -r build