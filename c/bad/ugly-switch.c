int main(void) {
  while (choice != 0) {
    switch (choice) {
      case 0:
        break;
      case 1:
        input(n);
        break;
      case 2:
        update(n);
        break;
      case 3:
        del(n);
        break;
      case 4:
        display(n);
        break;
      case 5:
        displayviadep(n);
        break;
      case 6:
        earn(n);
        break;
      case 7:
        displaydep(n);
        break;
      case 8:
        birthday(n);
        break;
      case 9:
        displaydate(n);
        break;
      case 10:
        search(n);
        break;
      default:
        printf("\nIncorrect choice");
    }

    menu();
    scanf("%d", &choice);
    clean();
  }
}
