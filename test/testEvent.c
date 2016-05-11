#include "../headers/event.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  Event newEvent = createEvent("Test", "Ceci est un évènement test", 12, 123);
  printf("Nom: %s\n",newEvent.name);
  printf("Description: %s\n",newEvent.description);
  printf("Début: %d\n",newEvent.begin);
  printf("Fin: %d\n",newEvent.end);
  printf("Bienvenue dans la gestion de calendrier!\n");
  FILE* fichier;
  fichier = fopen("../ressources/calendrier.ics","w+");
  if (fichier == NULL) {
    printf("Impossible de continuer, le fichier n'a pas pu être créer\n");
  }
  else {
    fputs("BEGIN:VCALENDAR\nVERSION:2.0\nPRODID:-//hacksw/handcal//NONSGML v1.0//EN", fichier);
  }
  return 0;
}
