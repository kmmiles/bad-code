#!/usr/bin/env bash

while read -r pkg; do
  echo "Hello $pkg"
done < pkgs.txt
