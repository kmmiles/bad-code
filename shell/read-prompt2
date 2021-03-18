#!/usr/bin/env bash

prompt_question() {
  local question answer
  question="$1"

  until [[ ${answer} == y ]] || [[ ${answer} == n ]]; do
    read -rp "$question (Y/n)? " answer
    answer=${answer:-y}
    answer=${answer,,}
  done

  [[ ${answer} == y ]] && echo 1 || echo 0
}

for q in general anime people; do
  answer=$(prompt_question $q)
done

general=$(prompt_question "General")
anime=$(prompt_question "Anime")
people=$(prompt_question "People")

categories="${general}${anime}${people}"
echo "${categories}"
