#!/usr/bin/env node

var user;
var place;
var money = 0;
var output;

onEvent("nameInput", "change", function( ) {
  user = getText("nameInput");
  updateScreen();
});

onEvent("placeDrop", "change", function( ) {
  place = getText("placeDrop");
  updateScreen();
});

onEvent("moneySlider", "input", function( ) {
  money = getNumber("moneySlider");
  setText("moneyOutput", money);
  updateScreen();
});


//Takes in the user's input and updates the screen.
function updateScreen() {
  if (place == "Fast Food" && money == 30) {
    output = "Chick-fil-A";
  } else if (place == "Fast Food" && money == 20) {
    output = "Five Guys";
  } else if (place == "Fast Food" && money == 10) {
    output = "McDonalds";
  } else if (place == "Italian" && money == 30) {
    output = "La Scala";
  } else if (place == "Italian" && money == 20) {
    output = "La Piazza";
  } else if (place == "Italian" && money == 10) {
    output = "La Focaccia";
  } else if (place == "Mexican" && money == 30) {
    output = "Chipotle";
  } else if (place == "Mexican" && money == 20) {
    output = "Moe's";
  } else if (place == "Mexican" && money == 10) {
    output = "Taco Bell";
  } else {money < 10} {
    output = "Costco for the free samples.";
  }
}
  var myText = "Hello " + user;
  myText = (myText + ". You should have " + output + ". ");
