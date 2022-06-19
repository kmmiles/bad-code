#!/usr/bin/env node

const user = {
    name: 'mike',
    sayHi() {
        console.log(`Hi ${this.name}`);
    },
};

//user.sayHi();

//const f = user.sayHi;

//f(); 
//setTimeout(user.sayHi, 1000); 
setTimeout( () => { 
  //user.sayHi(); 
  user.sayHi();
}, 1000);
"done";
