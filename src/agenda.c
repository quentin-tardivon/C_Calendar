#include "event.c"
#include "../headers/agenda.h"

Agenda createAgenda(char *name) {
  Agenda newAgenda;
  strcpy(newAgenda.name,name);
  newAgenda.nbEvenement = 0;
  newAgenda.tab_event = malloc(sizeof(Event)*newAgenda.nbEvenement);
}

Agenda addEvent(Agenda agenda, Event event) {
  agenda.nbEvenement +=1;
  agenda.tab_event = realloc(agenda.tab_event, agenda.nbEvenement * sizeof(Event));
}

void deleteAgenda(Agenda agenda) {
  free(agenda.tab_event);
}


int export(Agenda agenda, char* filename) {
  FILE* file;
  file = fopen(strcat("../ressources/", filename),"w+");
  if (file == NULL) {
    printf("Impossible de continuer, le fichier n'a pas pu être créer\n");
    return 1;
  }
  else {
    fputs("BEGIN:VCALENDAR\nVERSION:2.0\nPRODID:-//hacksw/handcal//NONSGML v1.0//EN", file);
  }
  int i;
  for (i = 0; i < agenda.nbEvenement; i++) {
    fputs("BEGIN:VEVENT\n", file);
    fprintf(file,"DTSTART:%s\n",agenda.tab_event[i].begin);
    fprintf(file, "DTEND:%s\n",agenda.tab_event[i].end);
    fprintf(file, "SUMMARY:%s\n",agenda.tab_event[i].name);
    fprintf(file, "DESCRIPTION:%s\n",agenda.tab_event[i].description);
    fputs("END:VEVENT", file);
  }

}
