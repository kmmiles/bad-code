#!/usr/bin/env bash

awk '{ for(f=3; f<=NF; f++) { if ($f < 0) $f=($f+360); } print env_var, $3, $4, $5, $6, $7, $8, $9}' gps.txt
