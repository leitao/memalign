#include "align.h"

int main(int argc, char **argv){
	int shift, b = 0;
	int align[] = {0, 256, 1024, 4096};

	for (b = 0; b < sizeof(align)/sizeof(int) ; b++) {
		printf("\n====================================\n");
		printf("Memory allocationg aligned in %d\n", align[b]);
		printf("====================================\n");
		for (shift = 0 ; shift < 8 ; shift++){
			if (shift == 0)
				printf("\nAlignment access\n");
			else
				printf("\nUn-aligned in +%d bytes\n", shift);

			default_allocation8(shift, align[b]);
			default_allocation16(shift, align[b]);
			default_allocation32(shift, align[b]);
			default_allocation64(shift, align[b]);
		}
	}
}

