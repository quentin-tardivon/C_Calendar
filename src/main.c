#include <stdio.h>
#include <stdlib.h>

int main() {
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

void create(char name_evenement,int horaire, char decription) {

}

void modify() {

}

void save(evenement) {

}
