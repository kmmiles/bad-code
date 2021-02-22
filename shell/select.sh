#!/usr/bin/env bash

nl=$'\n'
read -rp "[1] this is text nr 1 ${nl}[2] and this text nr 2 [1/2] " yn

PS3="Select something: "
select option in foo bar this that
do
    echo "Selected character: $option"
    echo "Selected number: $REPLY"
done
