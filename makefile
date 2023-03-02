output: main.o ColorEscape.o
	g++ main.o ColorEscape.o -o output

main.o: main.cpp
	g++ -c main.cpp

ColorEscape.o: ColorEscape.cpp
	g++ -c ColorEscape.cpp

clean:
	rm *.o output
