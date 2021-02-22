#!/usr/bin/env bash

one="one.txt"
two="two.txt"
three="three.txt"
four="four.txt"

for source in $one $two $three $four; do
  cp "$one" /tmp || echo "Failed to copy $source to /tmp, skipping"
done
