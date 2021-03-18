#!/usr/bin/env bash

printf "%.2f%%\n" "$(awk '/cpu /{print ($2+$4)*100/($2+$4+$5)}' < /proc/stat)"
