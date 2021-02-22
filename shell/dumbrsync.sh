#!/bin/bash

while read -r line; do
  if [[ ${line:0:1} == "#" ]]; then
    continue
  fi

  sourcedir="$(echo $line | cut -d' ' -f 1)"
  destdir="$(echo $line | cut -d' ' -f 2)"

  echo "rsync -Pauv \"$sourcedir\" \"$destdir\""
done < test.conf

