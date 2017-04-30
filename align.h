#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1024
#define BUFFER_SIZE 4096*1024
#define CHAR 'x'

extern void default_allocation8(int shift);
extern void default_allocation16(int shift);
extern void default_allocation32(int shift);
extern void default_allocation64(int shift);

extern time_t measure(void (*f)(uint8_t *), uint8_t *buf);
