#!/usr/bin/env bash

pid=$1
if [[ -z $pid ]]; then
    echo "Usage: $0 <pid>"
    exit 1    
fi

if ! [[ -d "/proc/$pid" ]]; then
    echo "Process does not exist"
    exit 1
fi

declare -ia pidList=() #make int array to store pids
pidList+=( "$pid" )
while [ -f "/proc/$pid/status" ]; do
    pid="$(awk '/PPid/ { print $2 }' "/proc/$pid/status")"
    [ "$pid" != '' ] && pidList+=( "$pid" )
done

declare -i lengthofList="((${#pidList[@]} - 1))"
for (( i=0; i <= "$lengthofList"; i++)); do
    if [ "$i" -eq 0 ]; then
      echo "Current PID: ${pidList[$i]}"
    elif [ "${pidList[$i]}" == 0 ]; then #skip pid = 0 bc it doesnt really count, its the swapper or sched
      break
    else
      echo "Parent($i) PID: ${pidList[$i]}"
    fi
done
