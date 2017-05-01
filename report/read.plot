# GNUPLOT config
# Read per alignment

set xlabel "Bytes per operation"
set ylabel "Time consumed to write a chunk of data"


set style line 1 lc rgb '#ad181f' lt 1 lw 2 pt 1 ps 1.5   # --- red
set style line 2 lc rgb '#0a60bd' lt 1 lw 2 pt 2 ps 1.5   # --- blue
set style line 3 lc rgb '#dda81f' lt 1 lw 2 pt 3 ps 1.5   # --- red
set style line 4 lc rgb '#006aa0' lt 1 lw 2 pt 4 ps 1.5   # --- blue
set style line 5 lc rgb '#dd181a' lt 1 lw 2 pt 5 ps 1.5   # --- red
set style line 6 lc rgb '#0d60ad' lt 1 lw 2 pt 6 ps 1.5   # --- blue
set style line 7 lc rgb '#d020ed' lt 1 lw 2 pt 7 ps 1.5   # --- blue
set style line 8 lc rgb '#03201e' lt 1 lw 2 pt 8 ps 1.5   # --- blue

plot 'tmp_write.tmp' index 1 with linespoints ls 1 title "Read time (aligned)", \
     ''    index 2 with linespoints ls 2 title "Read time (unaligned by 1)", \
     ''    index 3 with linespoints ls 3 title "Read time (unaligned by 2)", \
     ''    index 4 with linespoints ls 4 title "Read time (unaligned by 3)", \
     ''    index 5 with linespoints ls 5 title "Read time (unaligned by 4)", \
     ''    index 6 with linespoints ls 6 title "Read time (unaligned by 5)", \
     ''    index 7 with linespoints ls 7 title "Read time (unaligned by 6)", \
     ''    index 8 with linespoints ls 8 title "Read time (unaligned by 7)", \

pause -1
