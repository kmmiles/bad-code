#!/usr/bin/env node

Math.toJSON = function() {
    const proto = Object.getPrototypeOf(this)
    const jsonObj = Object.assign({}, this)

    Object.entries(Object.getOwnPropertyDescriptors(proto))
      .filter(([descriptor]) => typeof descriptor.get === 'function')
      .map(([key, descriptor]) => {
        if (descriptor && key[0] !== '_') {
          try {
            const val = (this)[key]
            jsonObj[key] = val
          } catch (error) {
            console.error(`Error calling getter ${key}`, error)
          }
        }
      })

    return jsonObj
}

console.log(JSON.stringify(Math));
//console.log(Math);

