a.out:head.h function.o func.o
	g++ function.o func.o -o link
function.o:head.h function.cpp func.cpp
	g++ -c -g function.cpp
func.o:head.h function.cpp func.cpp
	g++ -c -g func.cpp

clean:
	rm function.o func.o link
