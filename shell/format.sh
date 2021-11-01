#!/bin/bash

################################################################################
# Parse a delimated string, and returns a globally parsable array
# Globals:
#   NONE
# Arguments:
#   $1: delimated string
# Returns:
#   newline delimated string
################################################################################
string::split() {
  local string="$1"
  readonly string
  local delimiter="$2"
  readonly delimiter
  local Original_IFS="${IFS}"
  readonly Original_IFS

  local return_array
  return_array=()

  # local regex_comma="\\w,\\s*"
  local regex_comma="(\\w|\\s|\\/)*,(\\w|\\s|\\/)*"
  readonly regex_comma

  local regex_colon="(\\w|\\s|\\/)*:(\\w|\\s|\\/)*"
  readonly regex_colon

  local regex_semicolon="(\\w|\\s|\\/)*;(\\w|\\s|\\/)*"
  readonly regex_semicolon
  if [[ -n "${delimiter}" ]]; then
    Temporary_IFS="${delimiter}"
  else
    if [[ "${string}" =~ $regex_semicolon ]]; then
      Temporary_IFS=";"
    elif [[ "${string}" =~ $regex_colon ]]; then
      Temporary_IFS=":"
    elif [[ "${string}" =~ $regex_comma ]]; then
      Temporary_IFS=","
    else
      Temporary_IFS="${Original_IFS}"
    fi
  fi
  IFS="${Temporary_IFS}" read -ra return_array <<<"${string}"
  readonly return_array

  # bash can't return anything in the normal sense
  # this includes variables, strings, integers, arrays, etc
  # so the best method is to echo a newline delimated string
  # this is "globally" parsable
  # meaning that we don't have to do anything special to get an array from it
  # I.E. readarray -t array <<< "$(string::split "${foo}")"
  printf "%s\n" "${return_array[@]## }"
  return 0
}

string::truncate() {
  local string="$1"
  local width="$2"
  # Thanks to Dan for cool ellipses idea :)
  local ellipses=${3:no}
  if ((${#string} > width)); then
    string="${string:0:$width}"
    if [[ "${ellipses}" == "yes" ]]; then
      string="${string%???}"
      string="${string}..."
    fi
  fi
  printf "%s\n" "${string}"
}

################################################################################
# Formats data output
# Globals:
#   NONE
# Arguments:
#   $1: format type: csv, column, table, json, or yaml
#   $2: max width (defaults to 40)
#   $3: delimiter (defaults to semi-colon)
#   $4: delimited header fields
#   $*: delimited rows as individual strings
# Returns:
#   data parsed in requested format
################################################################################
format() {
  local re
  local format_type="$1"
  shift
  local max_width
  re_number='^[0-9]+$' # regular expression to test for a number
  # if the variable is empty or not an integer, use the default
  if [[ -z "$1" ]] || ! [[ "$1" =~ $re ]]; then
    max_width="40"
  else
    max_width="$1"
  fi
  shift
  local delimiter
  # if the variable is empty or not a singlec character, use the default
  if [[ -z "$1" ]] || [[ "$1" != "${1:0:1}" ]]; then
    delimiter=";"
  else
    delimiter="$1"
  fi
  shift
  local headers
  readarray -t headers <<<"$(string::split "${1}" "${delimiter}")"
  shift
  # after we shift off all the other args
  # only rows are left
  local rows=("$@")
  local row=()
  local columns=()
  local column=()
  local width=()
  local columns_max="${#headers[@]}"
  local rows_max="${#rows[@]}"
  local temp_string0
  local temp_string1
  local padding

  # Get the columns
  for ((i = 0; i < columns_max; i++)); do
    for ((r = 0; r < rows_max; r++)); do
      readarray -t row <<<"$(string::split "${rows[$r]}" "${delimiter}")"
      column+=("${row[$i]}${delimiter}")
    done
    # we set the temp string, and then remove an extra delimiter on the endf
    temp_string0="${column[*]}"
    temp_string0="${temp_string0%$delimiter}"
    # This appends to the end of the array, instead of overwriting it
    readarray -t -O "${#columns[@]}" columns <<<"${temp_string0}"
    unset column
  done
  # printf "Column: %s\n" "${columns[@]}"
  # exit 0

  # calculate the max width for each column, based on the largest string
  # and store it as an array, indexed as the column number
  for ((i = 0; i < columns_max; i++)); do
    width[$i]="0"
    if ((${#headers[$i]} < max_width)); then
      width[$i]="${#headers[$i]}"
    else
      width[$i]="${max_width}"
    fi
    readarray -t column <<<"$(string::split "${columns[$i]}" "${delimiter}")"
    for item in "${column[@]}"; do
      if ((${#item} > ${width[$i]})) && ((${#item} < max_width)); then
        width[$i]="${#item}"
      elif ((${#item} > max_width)); then
        width[$i]="${max_width}"
      fi
    done
  done

  # do the actual output
  case $format_type in
    "csv")
      # CSV is pretty simple (to output - I wouldn't want to try to write
      # RFC compliant code to import CSV!)
      for header in "${headers[@]}"; do
        printf "\"%s\"," "${header}"
      done
      printf "\b \n"
      for index in "${!rows[@]}"; do
        readarray -t row <<<"$(string::split "${rows[$index]}" "${delimiter}")"
        for item in "${row[@]}"; do
          printf "\"%s\"," "${item}"
        done
        printf "\b \n"
      done
      ;;
    "column")
      # Here we just just output same-width columns, nothing fancy
      for ((i = 0; i < columns_max; i++)); do
        printf "%-$((${width[$i]} + 4))s" "$(string::truncate "${headers[$i]}" "${width[$i]}" "yes")"
      done
      printf "\n"
      for ((i = 0; i < rows_max; i++)); do
        readarray -t row <<<"$(string::split "${rows[$i]}" ";")"
        for ((r = 0; r < columns_max; r++)); do
          printf "%-$((${width[$r]} + 4))s" "$(string::truncate "${row[$r]}" "${width[$r]}" "yes")"
        done
        printf "\n"
      done
      ;;
    "table")
      # for the table, we are using unicode box drawing characters
      # how they look will be font-dependent, but a good font will make it
      # look nice
      printf "┌"
      for ((i = 0; i < columns_max; i++)); do
        padding="$(printf "%$((${width[$i]} + 6))s")"
        printf "%s" "${padding// /─}"
        printf "\b┰"
      done
      printf "\b┐\n"
      for ((i = 0; i < columns_max; i++)); do
        printf "│ %-$((${width[$i]} + 4))s" "$(string::truncate "${headers[$i]}" "${width[$i]}" "yes")"
      done
      printf "│\n"
      printf "├"
      for ((i = 0; i < columns_max; i++)); do
        padding="$(printf "%$((((${width[$i]} + 6))))s")"
        printf "%s" "${padding// /─}"
        printf "\b┼"
      done
      printf "\b┤\n"
      for ((i = 0; i < rows_max; i++)); do
        readarray -t row <<<"$(string::split "${rows[$i]}" ";")"
        for ((r = 0; r < columns_max; r++)); do
          printf "│ %-$((${width[$r]} + 4))s" "$(string::truncate "${row[$r]}" "${width[$r]}" "yes")"
        done
        printf "│\n"
      done
      printf "└"
      for ((i = 0; i < columns_max; i++)); do
        padding="$(printf "%$((((${width[$i]} + 6))))s")"
        printf "%s" "${padding// /─}"
        printf "\b┴"
      done
      printf "\b┘\n"
      ;;
    "json")
      # There's not a lot of data to process here.
      # So we just make a list of objects, where each object
      # is a set of keys and values for each row.
      printf "[\n"
      for ((i = 0; i < rows_max; i++)); do
        printf "  {\n"
        for ((r = 0; r < columns_max; r++)); do
          if ((r < (columns_max - 1))); then
            temp_string0=","
          else
            temp_string0=""
          fi
          readarray -t row <<<"$(string::split "${rows[$i]}" "${delimiter}")"
          if [[ "${row[$r]}" =~ $re_number ]]; then
            temp_string1="${row[$r]}"
          else
            temp_string1="\"${row[$r]}\""
          fi
          printf "    \"%s\": %s%s\n" "${headers[$r]}" "${temp_string1}" "${temp_string0}"
        done
        if ((i < (rows_max - 1))); then
          temp_string0=","
        else
          temp_string0=""
        fi
        printf "  }%s\n" "${temp_string0}"
      done
      printf "]\n"
      ;;
    "yaml")
      # The yaml is just a literal json to yaml of the json output above
      for ((i = 0; i < rows_max; i++)); do
        for ((r = 0; r < columns_max; r++)); do
          if ((r == 0)); then
            temp_string0="- "
          else
            temp_string0="  "
          fi
          printf "%s" "${temp_string0}"
          readarray -t row <<<"$(string::split "${rows[$i]}" "${delimiter}")"
          printf "%s: %s\n" "${headers[$r]}" "${row[$r]}"
        done
      done
      ;;
  esac
}

# take in all text to be formated as a string
# commas seperate fields, newlines seperate lines
main() {
  printf "\nOutput:\n"
  format "$@"
  printf "\n"
}
main "$@"
