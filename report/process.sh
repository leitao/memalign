#!/bin/bash

OUTPUT="tmp"
WRITE="tmp_write"
READ="tmp_read"

## Run the benchmark
../a.out -v > tmp

cat $OUTPUT | grep 0\| | grep write > $WRITE
cat $OUTPUT | grep 0\| | grep \read > $READ

# Add a new gnuplot index after 4 lines
awk ' {print $4 " " $5;} NR % 4 == 0 { print "\n"; }' $WRITE > $WRITE.tmp
awk ' {print $4 " " $5;} NR % 4 == 0 { print "\n"; }' $READ > $READ.tmp

gnuplot -c write.plot $WRITE.tmp
gnuplot -c read.plot $READ.tmp

#rm $OUTPUT
rm $WRITE $WRITE.tmp $READ $READ.tmp
