#!/usr/bin/env bash

usage() {
  cat <<EOF
Usage: $0 [OPTIONS] <SOME_REQUIRED_ARGUMENT>

myprogram does something neat to the file <SOME_REQUIRED_ARGUMENT>.

OPTIONS

-r        <name>    Force program to go down rabbit hole <name>
-v                  Verbose outut
-h                  This message
EOF
}

usage
