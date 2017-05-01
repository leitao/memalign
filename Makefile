SRC = src

all:
	gcc -O0 -g src/align.c src/byte.c src/measure.c src/half.c src/word.c src/double.c src/alloc.c src/print.c -Wall

clean:
	rm -fr a.out
