run_GnuPlot: GnuPlotAirplane_build
	./build/GnuPlotAirplane

GnuPlotAirplane_build: build ./build/GnuPlotAirplane.o ./build/gnuplot.o
	gcc ./build/GnuPlotAirplane.o ./build/gnuplot.o -o ./build/GnuPlotAirplane

./build/GnuPlotAirplane.o: GnuPlotAirplane.c build
	gcc -c GnuPlotAirplane.c -o ./build/GnuPlotAirplane.o

./build/gnuplot.o: gnuplot.c build
	gcc -c gnuplot.c -o ./build/gnuplot.o

build:
	mkdir ./build

clean:
	rm -r build
