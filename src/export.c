#include <stdio.h>
#include <stdlib.h>

FILE* fichier;
fichier = fopen("../ressources/calendrier.ics","w+");
if (fichier == NULL) {
  printf("Impossible de continuer, le fichier n'a pas pu être créer\n");
}
else {
  fputs("BEGIN:VCALENDAR\nVERSION:2.0\nPRODID:-//hacksw/handcal//NONSGML v1.0//EN", fichier);
}
