link:head.h function.o func.o
	gcc function.o func.o -o link
function.o:head.h function.c func.c
	gcc -c -g function.c
func.o:head.h function.c func.c
	gcc -c -g func.c

clean:
	rm function.o func.o link
