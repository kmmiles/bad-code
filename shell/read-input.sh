#!/usr/bin/env bash

goodval="good"
userval=

while [ "$userval"  != "$goodval" ]; do
  read -rp "What value? " userval
  echo "userval: $userval"
done

echo "Cool."

