#include <stdio.h>
#include <stdlib.h>
#include "function.c"
#include "agenda.c"
#include "event.c"

int main() {

  int ext = 0;
  Agenda agenda1 = createAgenda("agenda1");
  printf("Bienvenue dans la gestion de calendrier!\n");
  while (ext == 0) {
    printf("Voulez-vous créer,importer un agenda ou quitter l'application\n(c/i/q)\n");
    char answer1;
    scanf("%c",&answer1);
    purge();
    if (answer1 == 'q') {
      ext = 1;
    }
    else {
      if (answer1 == 'i') {
        printf("Entrer le nom du fichier à importer:\n");
        char* name_file = malloc(sizeof(char)*50);
        fgets(name_file, sizeof(char)*50, stdin);
        clean(name_file);
        agenda1 = import(agenda1, name_file);
      }
      int extagenda = 0;
      while (extagenda == 0) {
        char answer2;
        printf("Voulez vous créer ou supprimer un évènement?\n(c pour créer/d pour supprimer/q pour quitter)\n");
        scanf("%c",&answer2);
        purge();
        if (answer2 == 'q') {
          extagenda = 1;
        }
        else if (answer2 == 'c') {
          agenda1 = eventCreation(agenda1);
        }
        else if (answer2 == 'd') {
          agenda1 = eventDelete(agenda1);
        }
        else {
          return 1;
        }
      }
      printf("Entrer un nom de fichier pour sauvegarder votre calendrier\n");
      char* name_file = malloc(sizeof(char)*40);
      fgets(name_file,sizeof(char)*40,stdin);
      clean(name_file);
      export(agenda1, name_file);
    }
  }
  return 0;
}
