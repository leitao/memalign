#  Unaligned Memory load and store benchmark 

## Summary 

Code that read and write on different types of memory addresses in order to measure read and write time depending on the memory location.


## Details

It allocates a memory block aligned in default, 256, 1024 and 4096 bytes.

Later, it writes byte, half word, word and double word on this block. It writes on aligned and then start to write on un-aligned address and measure the timing.

Depending on your system architecture, you see how unaligment on load/store affects performance.



## Concerns

This code is not NUMA-aware. Remote node allocation might influence in the performance