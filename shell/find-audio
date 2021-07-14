#!/usr/bin/env bash

#set -x

find ./testdir -mindepth 1 -type d |
  while read -r dir; do
    if find "$dir" -type f \( -iname \*.mp3 -o -iname \*.flacc \) | grep -q .; then
      echo "Delete $dir"
    else
      echo "Do NOT delete $dir"
    fi
  done
