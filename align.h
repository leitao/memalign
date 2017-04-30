#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 8
#define BUFFER_SIZE 4096*1024
#define CHAR 'x'

extern void default_allocation8(int shift, int align);
extern void default_allocation16(int shift, int align);
extern void default_allocation32(int shift, int align);
extern void default_allocation64(int shift, int align);


extern uint8_t *alloc(int shift, int align);

extern time_t measure(void (*f)(uint8_t *), uint8_t *buf);
