#!/usr/bin/env node

const data = [{"p1":10,"p2":2,"p3":4},{"p1":130,"p2":12,"p3":14},{"p1":0,"p2":20,"p3":4},{"p1":10,"p2":21,"p3":4},{"p1":10,"p2":22,"p3":4}]
const newData = [] //  [{name:'p1', data:[10,130,0,10,10]},{name:'p2',data:[2,12,20,21,22], .... so on }]
for (key of Object.keys(data[0])) {
  newData.push({
    name: key,
    data: data.map(o => o[key])
  })
}
console.log(newData)
