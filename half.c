#include "align.h"

void write16(uint8_t *ptr2){
	uint16_t *ptr = (uint16_t *) ptr2;
	int buf = BUFFER_SIZE/2;

	for (int i = 0; i< MAX; i++)
		for (int z = 0; z < buf ; z++ ){
			ptr[z] = i % 0xffff;
		}
}

void read16(uint8_t *ptr2){
	uint16_t *ptr = (uint16_t *) ptr2;
	int buf = BUFFER_SIZE/2;
	uint16_t w = 0;
	int i;

	for (i = 0; i< MAX; i++)
		for (int z = 0; z < buf ; z++ ){
			w = ptr[z];
		}

	// Just using w to disable Compiler error (Unused variable)
	i = w;
}

void default_allocation16(int shift, int align) {
	uint8_t *ptr;
	clock_t diff;

	ptr = alloc(shift, align);

	diff = measure(&write16, ptr);

	printf("\tWrite (half) :\t %Lf ms\n", (long double) diff/(1000 * 1000));

	diff = measure(&read16, ptr);

	printf("\tRead (half)  :\t %Lf ms\n", (long double) diff/(1000 * 1000));

	free(ptr - shift);
}
