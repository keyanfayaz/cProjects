OBJ = assn5Test.o heapReport.o linkedList.o
CC = gcc
CFLAGS = -Wall

assn5Test: $(OBJ)
	gcc -o assn5Test $(OBJ)

heapReport.o: heapReport.h

linkedList.o: linkedList.h

# "make cleanup" gets rid of all the files produced by the make rules above
cleanup:
	rm -f heapReport.o linkedList.o assn5Test.o assn5Test
