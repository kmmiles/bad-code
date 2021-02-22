#!/usr/bin/env bash

find ./ -print0 | xargs -0 -n1 cp 
#find ./ | xargs -n1 echo "test: \"$1\""

