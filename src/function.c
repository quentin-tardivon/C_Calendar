#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../headers/function.h"

Agenda eventCreation(Agenda agenda) {
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
  printf("Quel est la description de votre évènement?\n");
  fgets(newEvent.description,sizeof(char)*140, stdin);
  clean(newEvent.description);
  printf("Quel est le lieu de votre évènement?\n");
  fgets(newEvent.location,sizeof(char)*100, stdin);
  clean(newEvent.location);
  int correct_date = 0;
  while (correct_date == 0) {

    printf("Quel est la date de début? (Format JJ/MM/AAAA)\n");
    scanf("%d/%d/%d",&dd,&md,&yd);
    purge();
    date_begin.tm_year = yd - 1900;
    date_begin.tm_mon = md -1;
    date_begin.tm_mday = dd;
    printf("Heure de début de l'évènement? (Format HH:MM)\n");
    scanf("%d:%d",&h,&m);
    purge();
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
    purge();
    date_end.tm_year = yde - 1900;
    date_end.tm_mon = mde -1;
    date_end.tm_mday = dde;
    printf("Heure de fin de l'évènement? (Format HH:MM)\n");
    scanf("%d:%d",&he,&me);
    purge();
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
  agenda = addEvent(agenda, newEvent);
  printf("Cet évènement est-il annuel?\n(y/n)\n");
  char answer2 = 0;
  scanf("%c",&answer2);
  purge();
  if (answer2 == 'y') { //Ici, ça ne marche pas!
    int i;
    for (i = 0; i < 100; i++) {
      date_begin.tm_year = date_begin.tm_year+1;
      date_end.tm_year = date_end.tm_year+1;
      date = asctime(&date_begin);
      newEvent.begin = convertDate(date);
      date2 = asctime(&date_end);
      newEvent.end = convertDate(date2);
      agenda = addEvent(agenda, newEvent);
    }
  }
  return agenda;
}

Agenda eventDelete(Agenda agenda) {
  printf("Veuillez entrer le nom de l'évènement\n");
  char* name = malloc(sizeof(char)*40);
  fgets(name, sizeof(char)*40, stdin);
  clean(name);
  deleteEvent(agenda, name);
  return agenda;
}

Agenda import(Agenda agenda, char* name_file) {
  FILE* fichier = NULL;
  fichier = fopen(name_file, "r");
  if (fichier == NULL) {
    printf("Impossible d'ouvrir le fichier\nUn agenda vide a donc été créé.\n");
    return agenda;
  }
  else {
    char* line = malloc(sizeof(char)*300);
    char* var1 = malloc(sizeof(char)*300);
    Event newEvent;
    while (strstr(line, "END:VCALENDAR") == NULL) {
      fgets(line, 300, fichier);
      clean(line);
      if (strstr(line, "BEGIN:VEVENT") != NULL) {
        newEvent = createEvent();
      }
      else if (strstr(line, "SUMMARY:") != NULL){
        sscanf(line, "%[^:]:%[^\n]", var1,newEvent.name);
      }
      else if (strstr(line, "LOCATION:") != NULL){
        sscanf(line, "%[^:]:%[^\n]", var1,newEvent.location);
      }
      else if (strstr(line, "DESCRIPTION:") != NULL){
        sscanf(line, "%[^:]:%[^\n]", var1,newEvent.description);
      }
      else if (strstr(line, "DTSTART:") != NULL){
        sscanf(line, "%[^:]:%[^\n]", var1,newEvent.begin);
      }
      else if (strstr(line, "DTEND:") != NULL){
        sscanf(line, "%[^:]:%[^\n]", var1,newEvent.end);
      }
      else if (strstr(line,"END:VEVENT") != NULL) {
        agenda = addEvent(agenda,newEvent);
      }
    }
    free(line);
    free(var1);
    fclose(fichier);
    printf("Fichier importé\n");
    return agenda;
  }
}

void purge(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {}
}

void clean (char *chaine) {
    char *p = strchr(chaine, '\n');
    if (p)
    {
        *p = 0;
    }
    else
    {
        purge();
    }
}
