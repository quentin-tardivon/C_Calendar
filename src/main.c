#include <stdio.h>
#include <stdlib.h>
#include "agenda.c"
#include "event.c"

int main() {

  int ext = 0;
  Agenda agenda1 = createAgenda("agenda1");
  printf("Bienvenue dans la gestion de calendrier!\n");
  while (ext == 0) {
    char answer;
    printf("Voulez vous créer ou supprimer un évènement?\n(c pour créer/d pour supprimer/q pour quitter)\n");
    fgets(&answer, sizeof(&answer),stdin);
    clean(&answer);
    //scanf("%c",&answer);
    if (answer == 'q') {
      ext = 1;
    }
    else if (answer == 'c') {
      Event newEvent = createEvent();
      int yd = 0;
      int md = 0;
      int dd = 0;
      int h = 0;
      int m = 0;
      int yde = 0;
      int mde = 0;
      int dde = 0;
      int he = 0;
      int me = 0;
      struct tm date_begin;
      struct tm date_end;
      time_t secondes;
      struct tm instant;
      time(&secondes);
      char* date = NULL;
      date = malloc(sizeof(char)*30);
      char* date2 = NULL;
      date2 = malloc(sizeof(char)*30);
      instant = *localtime(&secondes);
      date_begin = instant;
      date_end = instant;


      printf("Quel est le nom de votre évènement?\n");
      fgets(newEvent.name, sizeof(char)*40, stdin);
      clean(newEvent.name);
      //scanf("%s",newEvent.name);
      printf("Quel est la description de votre évènement?\n");
      fgets(newEvent.description,sizeof(char)*140, stdin);
      clean(newEvent.description);
      //scanf("%s",newEvent.description);
      printf("Quel est le lieu de votre évènement?\n");
      fgets(newEvent.location,sizeof(char)*100, stdin);
      clean(newEvent.location);
      int correct_date = 0;
      while (correct_date == 0) {

        printf("Quel est la date de début? (Format JJ/MM/AAAA)\n");
        scanf("%d/%d/%d",&dd,&md,&yd);
        date_begin.tm_year = yd - 1900;
        date_begin.tm_mon = md -1;
        date_begin.tm_mday = dd;
        printf("Heure de début de l'évènement? (Format HH:MM)\n");
        scanf("%d:%d",&h,&m);
        date_begin.tm_hour = h;
        date_begin.tm_min = m;

        if (mktime(&date_begin) > mktime(&instant)) {
          correct_date = 1;
          if (date_begin.tm_isdst == 1) {
            date_begin.tm_hour = h-2 ;
          }
          else {
            date_begin.tm_hour = h-1;
          }
        }
        else {
          printf("La date est inférieure à la date actuelle.\n");
        }
      }

      date = asctime(&date_begin);
      newEvent.begin = convertDate(date);

      int correct_date2 = 0;
      while (correct_date2 == 0) {

        printf("Quel est la date de fin? (Format JJ/MM/AAAA)\n");
        scanf("%d/%d/%d",&dde,&mde,&yde);
        date_end.tm_year = yde - 1900;
        date_end.tm_mon = mde -1;
        date_end.tm_mday = dde;
        printf("Heure de fin de l'évènement? (Format HH:MM)\n");
        scanf("%d:%d",&he,&me);
        date_end.tm_hour = he;
        date_end.tm_min = me;

        if (mktime(&date_end) > mktime(&date_begin)) {
          correct_date2 = 1;
          if (date_end.tm_isdst == 1) {
            date_end.tm_hour = he-2 ;
          }
          else {
            date_end.tm_hour = he-1;
          }
        }
        else {
          printf("La date de fin est inférieure à la date de début.\n");
        }
      }
      date2 = asctime(&date_end);
      newEvent.end = convertDate(date2);
      agenda1 = addEvent(agenda1, newEvent);
      purger();
      printf("Cet évènement est-il annuel?\n(y/n)\n");
      char answer2 = 0;
      scanf("%c",&answer2);
      if (answer2 == 'y') { //Ici, ça ne marche pas!
        int i;
        for (i = 0; i < 100; i++) {
          date_begin.tm_year = date_begin.tm_year+1;
          date_end.tm_year = date_end.tm_year+1;
          date = asctime(&date_begin);
          newEvent.begin = convertDate(date);
          date2 = asctime(&date_end);
          newEvent.end = convertDate(date2);
          agenda1 = addEvent(agenda1, newEvent);
        }
      }
    }
    else if (answer == 'd') {
      printf("Veuillez entrer le nom de l'évènement\n");
      char* name = malloc(sizeof(char)*40);
      fgets(name, sizeof(char)*40, stdin);
      clean(name);
      deleteEvent(agenda1, name);
    }
    else {
      return 1;
    }
    clean(&answer);
  }
  export(agenda1, "calendrier.ics");
  return 0;
}
