# GNUPLOT config
# Read write per alignment

set xlabel "Bytes per operation"
set ylabel "Time consumed to move a chunk of data"

set style line 1 lc rgb '#0060ad' lt 1 lw 2 pt 3 ps 1.5   # --- blue
set style line 2 lc rgb '#dd181f' lt 1 lw 2 pt 5 ps 1.5   # --- red

plot 'tmp' index 0 with linespoints ls 2 title "Write time", \
     ''    index 1 with linespoints ls 1 title "Read time"

pause -1
