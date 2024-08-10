set terminal png
set output "Merge.png"
set title "MergeSort Performance"
set xlabel "Number of Elements"
set ylabel "Time (seconds)"
set grid
plot "-" with lines
5000  0.0012
10000 0.0025
15000 0.0041
20000 0.0057
25000000 0.0075
e