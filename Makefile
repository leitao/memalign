all:
	gcc -O0 -g align.c byte.c measure.c half.c word.c double.c -Wall

clean:
	rm -fr a.out
