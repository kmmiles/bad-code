int main(void) {
  for (int i = 0; S[i] != '\0'; i++) {
    // loop through all of S
    for (int j = 0; F[j] != '\0'; j++) {
      // loop through all of F

      tempDifference = abs(F[j] - S[i]);
      if (tempDifference > 13) {
        tempDifference = 26 - tempDifference;
      }

      // executes if it's a smaller difference
      if (tempDifference < smallestDifference) {
        smallestDifference = tempDifference;
      }
    }
    total += smallestDifference;  // add to total difference
    smallestDifference = 26;      // set value back
  }
  return total;  // returns total difference
}
