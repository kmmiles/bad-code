#!/bin/bash

function cmd()
{
    test $(find $1 -xdev -type f 2> /dev/null | wc -l) -eq 0 && echo 0 && return
    ret=$(find $1 -xdev 2> /dev/null  | xargs file | egrep 'statically linked' | wc -l)
    echo $ret
}

most_dir=$1
most_count=$(cmd $1)
shift
for dir in $@
do
    count=$(cmd $dir)
    test $count -gt $most_count && most_count=$count && most_dir=$dir
done

echo Directory $most_dir has the most statically linked files with $most_count
