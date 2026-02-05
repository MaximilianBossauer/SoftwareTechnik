run_GnuPlot: GnuPlotAirplane_build
	./build/GnuPlotAirplane
#Linker:
GnuPlotAirplane_build: build ./build/GnuPlotAirplane.o ./build/gnuplot.o
	gcc ./build/GnuPlotAirplane.o ./build/gnuplot.o -o ./build/GnuPlotAirplane

#Compiler:
./build/GnuPlotAirplane.o: ./src/GnuPlotAirplane.c build
	gcc -c ./src/GnuPlotAirplane.c -o ./build/GnuPlotAirplane.o

./build/gnuplot.o: ./src/gnuplot.c build
	gcc -c ./src/gnuplot.c -o ./build/gnuplot.o

build:
	mkdir ./build

clean:
	rm -r build