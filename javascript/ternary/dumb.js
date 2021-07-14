#!/usr/bin/env node

const newValue = 1;
const previousValue = 0;

this.hasIncreased = newValue > previousValue;
this.hasDecreased = newValue < previousValue;

console.log('hasIncreased: ' + this.hasIncreased);
console.log('hasDecreased: ' + this.hasDecreased);
