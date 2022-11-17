set datafile separator ','
set xdata time
set timefmt "%Y-%m-%dT%H:%M:%S"
set key autotitle columnhead
set ylabel "First Y Units" 
set xlabel 'Time'
set ytics 0.5
set xtics 1 
set style line 101 lw 3 lt rgb "#f62aa0" 
set style line 102 lw 3 lt rgb "#26dfd0" 

set xtics rotate # rotate labels on the x axis
set key right center # legend placement

set terminal pngcairo size 800,600 enhanced font 'Segoe UI,10'
set output 'example.png'
plot filename using 1:2 with lines, '' using 1:3 with lines
