const myList = ["Oct 7, 2009", "Nov 10, 2009", "Jan 10, 2009", "Oct 22, 2009", "Oct 12, 2009", "Oct 1, 2009", "Oct 2, 2009", "Oct 4, 2009", "Oct 3, 2009"];

function sortMonths(arr) {

  function getDay(string) {
    return string.match(/\d{1,2}(?=,)/g)
  }
  //console.log(myList[1].match(/\d{1,2}/g))
  arr.sort(function(a, b) {
    return getDay(a) - getDay(b)
  });
}
sortMonths(myList);
console.log(myList);
