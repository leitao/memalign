#include "align.h"

void write32(uint8_t *ptr2){
	uint32_t *ptr = (uint32_t *) ptr2;
	int buf = BUFFER_SIZE/4;

	for (int i = 0; i< MAX; i++)
		for (int z = 0; z < buf ; z++ ){
			ptr[z] = i % 0xffff;
		}
}

void read32(uint8_t *ptr2){
	uint32_t *ptr = (uint32_t *) ptr2;
	int buf = BUFFER_SIZE/4;
	uint32_t w = 0;
	int i;

	for (i = 0; i< MAX; i++)
		for (int z = 0; z < buf ; z++ ){
			w = ptr[z];
		}

	// Just using w to disable Compiler error (Unused variable)
	i = w;
}

void default_allocation32(int shift) {
	uint8_t *ptr;
	clock_t diff;

	// Allocating a bit extra to try unaligned
	ptr = (uint8_t *) malloc((BUFFER_SIZE + shift) * sizeof(uint8_t)) + shift;

	diff = measure(&write32, ptr);

	printf("\tWrite (word) :\t %Lf ms\n", (long double) diff/(1000 * 1000));

	diff = measure(&read32, ptr);

	printf("\tRead (word)  :\t %Lf ms\n", (long double) diff/(1000 * 1000));

	free(ptr - shift);
}
