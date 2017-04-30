#include "align.h"

void write8(uint8_t *ptr){
	for (int i = 0; i< MAX; i++)
		for (int z = 0; z < BUFFER_SIZE ; z++ ){
			ptr[z] = (i) % 0xff;
		}
}

void read8(uint8_t *ptr){
	uint8_t w = 0;
	int i;

	for (i = 0; i< MAX; i++)
		for (int z = 0; z < BUFFER_SIZE ; z++ ){
			w = ptr[z];
		}

	// Just using w to disable Compiler error (Unused variable)
	i = w;
}

void default_allocation8(int shift, int align) {
	uint8_t *ptr;
	clock_t diff;

	ptr = alloc(shift, align);

	diff = measure(&write8, ptr);

	printf("\tWrite (byte) :\t %Lf ms\n", (long double) diff/(1000 * 1000));

	diff = measure(&read8, ptr);

	printf("\tRead (byte)  :\t %Lf ms\n", (long double) diff/(1000 * 1000));

	free(ptr - shift);
}
