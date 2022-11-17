#!/usr/bin/env node

//const array1 = [1,2,3,4,5]
//const array2 = [3,4]
// let target_result = [1,2,5];
//
const array1 = [1, 1, 2]
const array2 = [2]


//const array3 = array1.filter(function(obj) { return array2.indexOf(obj) == -1; })
//const array3 = array1.filter(function(obj) { return array2.indexOf(obj) == -1; })
//console.log(array3)

//let unique1 = array1.filter((o) => array2.indexOf(o) === -1);
//let unique2 = array2.filter((o) => array1.indexOf(o) === -1);
//const unique = unique1.concat(unique2);

const uniq = array1.filter((o) => array2.indexOf(o) === -1).concat(array2.filter((o) => array1.indexOf(o) === -1))

console.log(uniq);
