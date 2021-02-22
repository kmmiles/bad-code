#!/bin/bash

regex="a-zA-Z0-9"
numberRegex="^[0-9]+$"

if [[ "$1" =~ $numberRegex ]]; then
  echo "here1"
  l="$1"
elif [[ "$2" =~ "$numberRegex" ]]; then
  echo "here2"
  l="$2"
else
  echo "here3"
  l="32"
fi

if [[ "$1" == yes ]] || [[ "$2" == yes ]]; then
  regex="${regex}!@#$%^&;:"
fi

cat /dev/urandom | tr -dc "$regex" | fold -w "$l" | head -n 1
