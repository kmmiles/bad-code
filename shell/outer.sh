#!/usr/bin/env bash

set -o xtrace

outer() {
  (while true; do sleep 1; done) & pid="$!"
  echo "Created background job "
  cleanup() { kill -- "$pid"; }
  trap 'cleanup' EXIT
}

outer
