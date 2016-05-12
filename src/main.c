#include <stdio.h>
#include <stdlib.h>
#include "agenda.c"
#include "event.c"

int main() {
  char answer;
  Agenda agenda1 = createAgenda("agenda1");
  printf("Bienvenue dans la gestion de calendrier!\n");
  printf("Voulez-vous créer un nouvel évènement?\ny/n\n");
  scanf("%c",&answer);
  if (answer == 'n') {
    return 0;
  }
  else if (answer == 'y') {
    Event newEvent = createEvent();
    int yd;
    int md;
    int dd;
    char* year = malloc(sizeof(char)*4);
    char* month = malloc(sizeof(char)*2);
    char* day =malloc(sizeof(char)*2);
    char* hours = malloc(sizeof(char)*5);
    printf("Quel est le nom de votre évènement?\n");
    scanf("%s",newEvent.name);
    printf("Quel est la description de votre évènement?\n");
    scanf("%s",newEvent.description);
    printf("Quel est la date de début? (Format JJ/MM/AAAA)\n");
    scanf("%d/%d/%d",&dd,&md,&yd);
    sprintf(year, "%d",yd);
    if (md > 9) {
      sprintf(month, "%d",md);
    }
    else {
      sprintf(month, "0%d",md);
    }
    if (dd > 9) {
      sprintf(day, "%d",dd);
    }
    else {
      sprintf(day, "0%d",dd);
    }
    printf("Heure de début de l'évènement? (Format HH:MM)\n");
    scanf("%s",hours);
    newEvent.begin = convertDate(year, day, month, hours);

    printf("Quel est la date de fin? (Format JJ/MM/AAAA)\n");
    scanf("%d/%d/%d",&dd,&md,&yd);
    sprintf(year, "%d",yd);
    if (md > 9) {
      sprintf(month, "%d",md);
    }
    else {
      sprintf(month, "0%d",md);
    }
    if (dd > 9) {
      sprintf(day, "%d",dd);
    }
    else {
      sprintf(day, "0%d",dd);
    }
    printf("Heure de fin de l'évènement? (Format HH:MM)\n");
    scanf("%s",hours);
    newEvent.end = convertDate(year, day, month, hours);
    agenda1 = addEvent(agenda1, newEvent);
    export(agenda1, "calendrier.ics");
    return 0;
  }
  else {
    return 1;
  }
}
