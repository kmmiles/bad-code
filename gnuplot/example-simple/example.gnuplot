set datafile separator ","
set autoscale fix
set key outside right center

set title "Title"
plot "example.csv" using 4 title "LineTitle" with lines

pause -1
