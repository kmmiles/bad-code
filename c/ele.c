#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TITLE_BASICS_PATH "./data/title_basics.tsv"
#define TITLE_RATINGS_PATH "./data/title_ratings.tsv"

FILE* ouvertureRatings(void) {
  FILE* pointeur_database = NULL;
  pointeur_database = fopen(TITLE_RATINGS_PATH, "r");

  // Regarder si la lecture est bien faite.
  if (pointeur_database == NULL) {
    printf("Erreur dans la lecture de ../includes/title_ratings.tsv %s\n",
           strerror(errno));
    exit(EXIT_FAILURE);
  }
  return pointeur_database;
}

int main(void) {
  FILE* tittleDB1 = ouvertureRatings();
  fclose(tittleDB1);

  FILE* tittleDB2 = ouvertureRatings();
  ;
  fclose(tittleDB2);

  FILE* tittleDB3 = ouvertureRatings();
  ;
  fclose(tittleDB3);

  FILE* tittleDB4 = ouvertureRatings();
  ;
  fclose(tittleDB4);

  return 0;
}
