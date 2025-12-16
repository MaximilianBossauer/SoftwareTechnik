build:
	mkdir build

compile_printf: build
	gcc -o build/printf src/tut_2_printf.c

compile_scanf: build
	gcc -o build/scanf src/tut_2_scanf.c

run_printf: compile_printf
	./build/printf

run_scanf: compile_scanf
	./build/scanf

clean:
	rmdir build /s /q