#!/bin/bash

# Use awk as a calculator
calc() {
  awk "BEGIN {print $*}"
}

################################################################################
# Check for installed packages
# Arguments:
#   Variable number of package names
# Returns:
#   1 if packages are not installed
################################################################################
chkpkg() {
  # no packages specified
  if [[ $# -eq 0 ]]; then
    return 1
  fi

  for pkg in "$@"; do
    dpkg -V "$pkg" > /dev/null 2>&1 || return 1
  done
}

################################################################################
# Check for programs in PATH
# Arguments:
#   Variable number of program names
# Returns:
#   1 if any programs are not in PATH
################################################################################
chkpath() {
  # no programs specified
  if [[ $# -eq 0 ]]; then
    return 1
  fi

  for prog in "$@"; do
    command -v "$prog" > /dev/null 2>&1 || return 1
  done
}

# basic text colors
TEXT_BOLD=$(tput bold)
TEXT_RED=$(tput setaf 1)
TEXT_GREEN=$(tput setaf 2)
TEXT_YELLOW=$(tput setaf 3)
TEXT_BLUE=$(tput setaf 4)
TEXT_NORMAL=$(tput sgr0)
export TEXT_BOLD TEXT_RED TEXT_GREEN TEXT_YELLOW TEXT_BLUE TEXT_NORMAL

################################################################################
# Downloads url
# Arguments:
#   The URL
# Outputs:
#   Absolute path of downloaded file on success
# Returns:
#   1 on error
################################################################################
dl() {
  local url filepath filename

  url="$1"
  if [[ -z "$url" ]]; then
    return 1
  fi

  filename=$(basename "$url")
  filepath="$HOME"/Downloads/"$filename"

  # destination directory must exist
  if [[ ! -d "$HOME"/Downloads ]]; then
    log_err "Directory does not exist \"$HOME/Downloads\"."
    return 1 
  fi

  # download file
  if [[ ! -f "$filepath" ]]; then
    log_info "Downloading \"$url\" to \"$HOME/Downloads\"..."
    if ! curl -sfL -o "$filepath" "$url"; then
      log_err "Failed to download \"$url\"."
      return 1
    fi
  fi

  # print path of downloaded file
  echo "$filepath"
}


# determine some info about the platform
IS_UBUNTU=$(grep -q "ID=ubuntu" /etc/os-release && echo true || echo false)
IS_DEBIAN=$(grep -q "ID=debian" /etc/os-release && echo true || echo false)
IS_WSL=$(command -v "wslpath" > /dev/null 2>&1 && echo true || echo false)
if [[ "$(systemctl get-default)" == "graphical.target" ]]; then
  IS_GUI=true
else
  IS_GUI=false
fi

if [[ "$(id -u)" == "0" ]]; then
  IS_ROOT=true
else
  IS_ROOT=false
fi

export IS_ROOT IS_UBUNTU IS_DEBIAN IS_WSL IS_GUI
# log message functions

__LOGFILE=
export __LOGFILE

################################################################################
# Print plain message to stdout (or __LOGFILE)
# Globals:
#   __LOGFILE
# Arguments:
#   The message
################################################################################
log_msg() {
  if [[ "$__LOGFILE" != "" ]]; then
    puts "$(log_get_title)${1}" >> "$__LOGFILE"
  else
    puts "$(log_get_title)${1}"
  fi
}

################################################################################
# Print red error message to stderr (or __LOGFILE)
# Globals:
#   __LOGFILE
# Arguments:
#   The message
################################################################################
log_err() {
  if [[ "$__LOGFILE" != "" ]]; then
    puts "$(log_get_title)${1}" >> "$__LOGFILE"
  else
    >&2 puts-red "$(log_get_title)${1}"
  fi
}

################################################################################
# Print yellow warning message to stderr (or __LOGFILE)
# Globals:
#   __LOGFILE
# Arguments:
#   The message
################################################################################
log_warn() {
  if [[ "$__LOGFILE" != "" ]]; then
    puts "$(log_get_title)${1}" >> "$__LOGFILE"
  else
    >&2 puts-yellow "$(log_get_title)${1}"
  fi
}

################################################################################
# Print blue info message to stderr (or __LOGFILE)
# Globals:
#   __LOGFILE
# Arguments:
#   The message
################################################################################
log_info() {
  if [[ "$__LOGFILE" != "" ]]; then
    puts "$(log_get_title)${1}" >> "$__LOGFILE"
  else
    >&2 puts-blue "$(log_get_title)${1}"
  fi
}

################################################################################
# Sets log* functions to write to a file instead of stdout/stderr
#
# Globals:
#   __LOGFILE
# Arguments:
#   None
################################################################################
log_use_file() {
  local logrel

  logrel="logs/$(basename "$0").log"
  __LOGFILE="${__ROOT}/$logrel"

  mkdir -p "${__ROOT}/logs"
  rm -f "$__LOGFILE"
  touch "$__LOGFILE"
}

################################################################################
# Print prefix string of log messages (program named wrapped in brackets).
# Globals:
#   SOURCE
# Arguments:
#   None
# Outputs:
#   Prefix string or empty if not a script    
################################################################################
log_get_title() { echo "[$(basename "$__FILE")] "; }

mime_type() {
  local filename
  filename="$1"

  if [[ -z "$filename" ]]; then
    log_err "Usage: mime-type <filename>"
    return 1
  fi

  file --mime-type -b  "$1"
}


# functions dealing with paths

################################################################################
# Convert absolute path to path relative to current working directory
# Arguments:
#   Absolute path
# Outputs:
#   Relative path
################################################################################
relpath() { realpath -s --relative-to="$PWD" "$1" ; }

################################################################################
# Convert path to absolute
# Arguments:
#   Path
# Outputs:
#   Absolute path
################################################################################
abspath() { realpath -s "$1" ; }


################################################################################
# Add ppa repository if it doesn't already exist
# Arguments:
#   ppa url e.g. ppa:aslatter/ppa
# Returns:
#   1 if bad ppa url
################################################################################
ppa_add() {
  ppa="${1:-}"
  if [[ -z "$ppa" ]]; then
    return 1
  fi

  # sanity check the ppa url
  p="$(echo "$ppa" | cut -d':' -f 1)"
  if [[ "$p" != "ppa" ]]; then
    return 1
  fi

  p="$(echo "$ppa" | cut -d':' -f 2)"
  if ! grep -q "$p" /etc/apt/sources.list.d/*.list; then
    sudo add-apt-repository "$ppa"
  fi
}

################################################################################
# Functions to print a message in various colors
# Globals:
#   None
# Arguments:
#   The message
################################################################################
puts()  { printf "%s\n" "${1}" ; }
puts-red() { printf "%s\n" "${TEXT_BOLD}${TEXT_RED}${1}${TEXT_NORMAL}" ; }
puts-green() { printf "%s\n" "${TEXT_BOLD}${TEXT_GREEN}${1}${TEXT_NORMAL}" ; }
puts-blue() { printf "%s\n" "${TEXT_BOLD}${TEXT_BLUE}${1}${TEXT_NORMAL}" ; }
puts-yellow() { printf "%s\n" "${TEXT_BOLD}${TEXT_YELLOW}${1}${TEXT_NORMAL}" ; }
# slackware style OK/FAIL status logs

__STATUS_MSG=
export __STATUS_MSG

################################################################################
# Print and save the status message
# Globals:
#   STATUS_MSG
# Arguments:
#   The message
# Oututs:
#   The message
################################################################################
status_msg() {
  STATUS_MSG="$1"
  printf '%s' "$STATUS_MSG"
}

################################################################################
# Prints green [OK] after the status message
# Arguments:
#   None
# Outputs:
#   See description
################################################################################
status_ok() {
  local len
  len=$(status_msglen)
  printf "%${len}s\\n" "[${TEXT_BOLD}${TEXT_GREEN} OK ${TEXT_NORMAL}]"
}

################################################################################
# Prints red [FAIL] after the status message
# Arguments:
#   None
# Outputs:
#   See description
################################################################################
status_fail() {
  local len
  len=$(status_msglen)
  printf "%${len}s\\n" "[${TEXT_BOLD}${TEXT_RED}FAIL${TEXT_NORMAL}]"

  if [[ -n "$__LOGFILE" ]]; then
    2>&1 puts-red "Check logfile for details: $(relpath "$__LOGFILE")"
  fi
}

################################################################################
# Used for justifying the OK/FAIL text after each status message
# Globals:
#   STATUS_MSG
# Arguments:
#   None
# Outputs:
#   console width minus the current status message
################################################################################
status_msglen() {
  local msglen="${#STATUS_MSG}"
  local columns=
  columns=$(tput cols)
  echo "$((columns-msglen))"
}

################################################################################
# Create a symlink
# Arguments:
#   src
#   dest
# Returns:
#   1 on bad input
################################################################################
symlink() {
  local src
  local dest

  src="${1:-}"
  dest="${2:-}"

  # quick sanity check of inputs
  if [[ -z "$src" || -z "$dest" ]]; then
    return 1
  fi

  # convert paths to absolute
  src="$(abspath "$src")"
  dest="$(abspath "$dest")"

  # don't overwrite existing files that aren't links
  if [[ -f "$dest" && ! -h "$dest" ]]; then
    backup="$(dirname "$dest")/$(basename "$dest").$(date '+%s')"
    log_warn "Cowardly refusing to overwrite, moving \"$dest\" -> \"$backup\""
    mv -f "$dest" "$backup"
  else
    rm -f "$dest"
  fi

  log_info "Linking \"$src\" -> \"$dest\""
  ln -sf "$src" "$dest"
}

################################################################################
# Function to call when trapping ERR
# Arguments:
#   None
# Returns:
#   Return code of source error
################################################################################
handle_trap_err() {
  local s=$?
  log_err "$0:$LINENO returned $s (cmd=\`$BASH_COMMAND\`)"
  exit $s
}

################################################################################
# get the windows username (only applies to WSL2)
# Arguments:
#   Letter of primary windows drive (e.g. "c")
# Outputs:
#   username
################################################################################
get_win_user() {
  local win_drive="$1"
  declare -a invalid_users
  invalid_users=( Administrator Default DefaultAccount Guest Public WDAGUtilityAccount )
  find "/mnt/$win_drive/Users" -mindepth 1 -maxdepth 1 -type d |
    while read -r line; do
      # skip invalid users
      user="$(basename "$line")"
      if [[ ${invalid_users[*]} =~ ${user} ]]; then
        continue
      fi
    
      # print valid user and done
      echo "$user"
      break
    done
}

################################################################################
# main
################################################################################
main() {
  # Directory of the script that sourced this library. 
  __DIR="$(cd "$(dirname "${BASH_SOURCE[2]}")" && pwd)"
  # Filename of the script that sourced this library.
  __FILE="${__DIR}/$(basename "${BASH_SOURCE[2]}")"
  # Parent directory of the script that sourced this library.
  __ROOT="$(cd "$(dirname "${__DIR}")" && pwd)"
  export __DIR __FILE __ROOT __SOURCE

  # set options
  set -o errexit
  set -o pipefail
  set -o nounset

  # set trap
  trap handle_trap_err ERR
}

main "$@"
