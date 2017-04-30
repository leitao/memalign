#include "align.h"

void write64(uint8_t *ptr2){
	uint64_t *ptr = (uint64_t *) ptr2;
	int buf = BUFFER_SIZE/8;

	for (int i = 0; i< MAX; i++)
		for (int z = 0; z < buf ; z++ ){
			ptr[z] = i % 0xffff;
		}
}

void read64(uint8_t *ptr2){
	uint64_t *ptr = (uint64_t *) ptr2;
	int buf = BUFFER_SIZE/8;
	uint64_t w = 0;
	int i;

	for (i = 0; i< MAX; i++)
		for (int z = 0; z < buf ; z++ ){
			w = ptr[z];
		}

	// Just using w to disable Compiler error (Unused variable)
	i = w;
}

void default_allocation64(int shift) {
	uint8_t *ptr;
	clock_t diff;

	// Allocating a bit extra to try unaligned
	ptr = (uint8_t *) malloc((BUFFER_SIZE + shift) * sizeof(uint8_t)) + shift;

	diff = measure(&write64, ptr);

	printf("\tWrite (dword) :\t %Lf ms\n", (long double) diff/(1000 * 1000));

	diff = measure(&read64, ptr);

	printf("\tRead (dword)  :\t %Lf ms\n", (long double) diff/(1000 * 1000));

	free(ptr - shift);
}
