#include <stdio.h>
#include <stdlib.h>
#include "agenda.c"
#include "event.c"

static void purger(void)
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
    {}
}

static void clean (char *chaine)
{
    char *p = strchr(chaine, '\n');

    if (p)
    {
        *p = 0;
    }

    else
    {
        purger();
    }
}

int main() {
  char answer;
  Agenda agenda1 = createAgenda("agenda1");
  printf("Bienvenue dans la gestion de calendrier!\n");
  printf("Voulez-vous créer un nouvel évènement?\ny/n\n");
  fgets(&answer, sizeof(&answer),stdin);
  clean(&answer);
  //scanf("%c",&answer);
  if (answer == 'n') {
    return 0;
  }
  else if (answer == 'y') {
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
    fgets(newEvent.name, sizeof(newEvent.name), stdin);
    clean(newEvent.name);
    //scanf("%s",newEvent.name);
    printf("Quel est la description de votre évènement?\n");
    fgets(newEvent.description,sizeof(newEvent.description), stdin);
    clean(newEvent.description);
    //scanf("%s",newEvent.description);
    int correct_date = 0;
    while (correct_date == 0) {

      printf("Quel est la date de début? (Format JJ/MM/AAAA)\n");
      scanf("%d/%d/%d",&dd,&md,&yd);
      date_begin.tm_year = yd - 1900;
      date_begin.tm_mon = md -1;
      date_begin.tm_mday = dd -1;
      printf("Heure de début de l'évènement? (Format HH:MM)\n");
      scanf("%d:%d",&h,&m);
      if (date_begin.tm_isdst == 1) {
        date_begin.tm_hour = h - 2;
      }
      else {
        date_begin.tm_hour = h - 1;
      }
      date_begin.tm_min = m;

      if (mktime(&date_begin) > mktime(&instant)) {
        correct_date = 1;
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
      date_end.tm_mday = dde -1;
      printf("Heure de fin de l'évènement? (Format HH:MM)\n");
      scanf("%d:%d",&he,&me);
      if (date_end.tm_isdst == 1) { //Ne marche pas
        date_end.tm_hour = he - 2;
      }
      else {
        date_end.tm_hour = he - 1;
      }
      date_end.tm_min = me;

      if (mktime(&date_end) > mktime(&date_begin)) {
        correct_date2 = 1;
      }
      else {
        printf("La date de fin est inférieure à la date de début.\n");
      }
    }
    date2 = asctime(&date_end); //segfault
    newEvent.end = convertDate(date2);
    agenda1 = addEvent(agenda1, newEvent);
    export(agenda1, "calendrier.ics");
    return 0;
  }
  else {
    return 1;
  }
}
