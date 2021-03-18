#!/usr/bin/env bash

prompt_question() {
  local question answer
  question="$1"

  until [[ ${answer} == y ]] || [[ ${answer} == n ]]; do
    read -rp "$question (y/N)? " answer
    answer=${answer:-n}
    answer=${answer,,}
  done

  [[ ${answer} == y ]] && return 0 || return 1
}

if prompt_question "Continue"; then
  echo "Yes indeed"
else
  echo "No."
fi
