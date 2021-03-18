#!/bin/bash

regex="a-zA-Z0-9"
numberRegex="^[0-9]+$"

if [[ "$1" =~ $numberRegex ]]; then 
  l="$1"
elif [[ "$2" =~ $numberRegex ]]; then
  l="$2"
else
  l="32"
fi

if [[ "$1" == yes ]] || [[ "$2" == yes ]]; then
  regex="${regex}!@#$%^&;:"
fi

cat /dev/urandom | tr -dc "$regex" | fold -w "$l" | head -n 1
