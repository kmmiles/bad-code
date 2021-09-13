const str=150;
const dex=50;
const lvl=20;

console.log('melee damage');
console.log('=============');
const rogue=(str+dex) * lvl / 200;
const warrior=str * lvl / 100;

console.log(`rogue: ${rogue}`);
console.log(`warrior: ${warrior}`);
