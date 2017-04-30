#include "align.h"

int main(int argc, char **argv){
	int z = 0;
	for ( z = 0 ; z < 8 ; z++){
		default_allocation8(z);
		default_allocation16(z);
		default_allocation32(z);
		default_allocation64(z);
	}
}

