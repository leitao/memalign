#!/bin/bash

OUTPUT="tmp"
WRITE="tmp_write"

../a.out -v > tmp

cat $OUTPUT | grep 0\| | grep write > $WRITE

# Add a new gnuplot index after 6 lines
awk ' {print $4 " " $5;} NR % 6 == 0 { print "\n"; }' $WRITE > $WRITE.tmp

gnuplot -c write.plot $WRITE.tmp
