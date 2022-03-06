#!/usr/bin/env node

if ('SNAP' in process.env) {
  console.log('yes, this is a snap');
} else {
  console.log('no, this is not a snap');
}
